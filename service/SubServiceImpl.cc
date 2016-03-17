#include "SubServiceImpl.hh"

#include "zmq.h"
#include "Log.hh"

namespace zod
{

SubServiceImpl::SubServiceImpl(const std::string& addr, MsgCallback* callback):
    addr_(addr),
    callback_(callback),
    context_(nullptr),
    sub_(nullptr),
    is_run_(false)
{
  ZOD_TRACE <<"SubServiceImpl::SubServiceImpl()";

  msg_queue_.reset( new soil::MsgQueue<Msg, MsgCallback>(callback_) );
  
  context_ = zmq_ctx_new();
  assert( context_ );

  sub_ = zmq_socket(context_, ZMQ_SUB);
  assert( sub_ );

  ZOD_INFO <<"sub addr: " <<addr_;

  if( zmq_connect(sub_, addr_.data())<0 )
  {
    std::string err = "sub connect error.\n";
    throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
  }

  if( zmq_setsockopt(sub_, ZMQ_SUBSCRIBE, "", 0)<0 )
  {
    std::string err = "set subscribe options failed.\n";
    throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
  }

  is_run_ = true;
  recv_thread_.reset( new std::thread(&SubServiceImpl::run, this) );
}

SubServiceImpl::~SubServiceImpl()
{
  ZOD_TRACE <<"SubServiceImpl::~SubServiceImpl()";

  is_run_ = false;
  
  zmq_close( sub_ );

  zmq_ctx_destroy( context_ );

  recv_thread_->join();
}

void SubServiceImpl::run()
{
  ZOD_TRACE <<"SubServiceImpl::run()";

  while( is_run_ )
  {
    zmq_msg_t msg;
    zmq_msg_init( &msg );

    if( zmq_msg_recv(&msg, sub_, 0)<0 )
    {
      ZOD_ERROR <<"recv msg failed.\n"
                 <<zmq_strerror(zmq_errno());
    }
    else
    {
      std::unique_ptr<Msg> data( new Msg(zmq_msg_data(&msg), zmq_msg_size(&msg)) );
      msg_queue_->pushMsg( data.release() );
    }

    zmq_msg_close( &msg );
  }

  ZOD_DEBUG <<"SubServiceImpl::run()  done.";
}


SubService* SubService::create(const std::string& addr, MsgCallback* callback)
{
  return new SubServiceImpl(addr, callback);
}

};
