#include "RecvService.hh"
#include "Log.hh"
#include "zmq.h"

namespace zod
{

RecvService::RecvService(SockType sock_type, const std::string& addr, MsgCallback* callback):
    Service(sock_type, CONNECT, addr),
    callback_(callback),
    is_run_(false)
{
  ZOD_TRACE <<"RecvService::RecvService()";

  msg_queue_.reset( new soil::MsgQueue<Msg, MsgCallback>(callback_) );

  if( sock_type==SUB_SOCK )
  {
    if( zmq_setsockopt(sock(), ZMQ_SUBSCRIBE, "", 0)<0 )
    {
      std::string err = "set subscribe options failed.\n";
      throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
    }
  }

  is_run_ = true;
  recv_thread_.reset( new std::thread(&RecvService::run, this) );
}

RecvService::~RecvService()
{
  ZOD_TRACE <<"RecvService::~RecvService()";

  is_run_ = false;

  stop();
  
  recv_thread_->join();
}


void RecvService::run()
{
  ZOD_TRACE <<"RecvService::run()";

  while( is_run_ )
  {
    zmq_msg_t msg;
    zmq_msg_init( &msg );

    if( zmq_msg_recv(&msg, sock(), 0)<0 )
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

  ZOD_DEBUG <<"RecvServiceImpl::run()  done.";
}

};
