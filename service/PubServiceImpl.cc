#include "PubServiceImpl.hh"

#include "zmq.h"
#include "Log.hh"

namespace zod
{

PubServiceImpl::PubServiceImpl(ServiceType type, const std::string& addr):
    addr_(addr),
    context_(nullptr),
    pub_(nullptr)
{
  ZOD_TRACE <<"PubServiceImpl::PubServiceImpl()";

  context_ = zmq_ctx_new();
  assert( context_ );

  pub_ = zmq_socket(context_, ZMQ_PUB);
  assert( pub_ );

  ZOD_INFO <<"pub addr: " <<addr_;

  switch( type )
  {
    case BIND:
      if( zmq_bind(pub_, addr_.data())<0 )
      {
        std::string err = "pub bind error.\n";
        throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
      }
      break;

    case CONNECT:
      if( zmq_connect(pub_, addr_.data())<0 )
      {
        std::string err = "pub connect error.\n";
        throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
      }
      break;

    default:
      throw std::runtime_error("unsupported service type.");
  };

}

PubServiceImpl::~PubServiceImpl()
{
  ZOD_TRACE <<"PubServiceImpl::~PubServiceImpl()";
  
  zmq_close( pub_ );

  zmq_ctx_destroy( context_ );
}

void PubServiceImpl::sendMsg(const std::string& msg)
{
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  zmq_msg_t zmq_msg;
  zmq_msg_init_size(&zmq_msg, msg.length()+1);

  memset(zmq_msg_data(&zmq_msg), 0x0, msg.length()+1);
  memcpy(zmq_msg_data(&zmq_msg), msg.data(), msg.length());

  if( zmq_msg_send(&zmq_msg, pub_, 0)<0 )
  {
    zmq_msg_close(&zmq_msg);

    ZOD_ERROR <<"msg send failed.\n"
              <<zmq_strerror(zmq_errno());
  }
  
}

void PubServiceImpl::sendMsg(void* msg, unsigned int len)
{
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  zmq_msg_t zmq_msg;
  zmq_msg_init_size(&zmq_msg, len);

  memset(zmq_msg_data(&zmq_msg), 0x0, len);
  memcpy(zmq_msg_data(&zmq_msg), msg, len);

  if( zmq_msg_send(&zmq_msg, pub_, 0)<0 )
  {
    zmq_msg_close(&zmq_msg);

    ZOD_ERROR <<"msg send failed.\n"
              <<zmq_strerror(zmq_errno());
  }

}

PubService* PubService::create(const std::string& addr, ServiceType type)
{
  return new PubServiceImpl(type, addr);
}

};
