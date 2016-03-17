#include "Service.hh"
#include "Log.hh"

#include "zmq.h"

namespace zod
{

Service::Service(SockType sock_type, ServiceType service_type, const std::string& addr):
    addr_(addr),
    context_(nullptr),
    sock_(nullptr)

{
  ZOD_TRACE <<"Service::Service()";

  context_ = zmq_ctx_new();
  assert( context_ );

  sock_ = createSock(sock_type);
  assert( sock_ );

  ZOD_INFO <<"addr: " <<addr_;

  switch( service_type )
  {
    case BIND:
      if( zmq_bind(sock_, addr_.data())<0 )
      {
        std::string err = "bind error.\n";
        throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
      }
      break;

    case CONNECT:
      if( zmq_connect(sock_, addr_.data())<0 )
      {
        std::string err = "connect error.\n";
        throw std::runtime_error( err+zmq_strerror(zmq_errno()) );
      }
      break;

    default:
      throw std::runtime_error("unsupported service type.");
  };

}

Service::~Service()
{
  ZOD_TRACE <<"Service::~Service()";

  stop();
}

void Service::send(const void* msg, unsigned int len)
{
  ZOD_TRACE <<"Service::send()";

  zmq_msg_t zmq_msg;
  zmq_msg_init_size(&zmq_msg, len);

  memset(zmq_msg_data(&zmq_msg), 0x0, len);
  memcpy(zmq_msg_data(&zmq_msg), msg, len);

  if( zmq_msg_send(&zmq_msg, sock_, 0)<0 )
  {
    zmq_msg_close(&zmq_msg);

    ZOD_ERROR <<"msg send failed.\n"
              <<zmq_strerror(zmq_errno());
  }

}

void Service::stop()
{
  ZOD_TRACE <<"Service::stop()";

  if( sock_ )
    zmq_close( sock_ );

  if( context_ )
    zmq_ctx_destroy( context_ );

  sock_ = nullptr;
  context_ = nullptr;
  
}

void* Service::createSock(SockType sock_type)
{
  void* sock = nullptr;
  
  switch( sock_type )
  {
    case PUB_SOCK:
      sock = zmq_socket(context_, ZMQ_PUB);
      break;

    case SUB_SOCK:
      sock = zmq_socket(context_, ZMQ_SUB);
      break;

    case PUSH_SOCK:
      sock = zmq_socket(context_, ZMQ_PUSH);
      break;

    case PULL_SOCK:
      sock = zmq_socket(context_, ZMQ_PULL);
      break;
  }

  return sock;
}
  

};
