#ifndef ZOD_SERVICE_HH
#define ZOD_SERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod
{

typedef enum
{
  PUB_SOCK,
  SUB_SOCK,
  PUSH_SOCK,
  PULL_SOCK
}SockType;

class Service
{
 public:
  Service(SockType sock_type, ServiceType service_type, const std::string& addr);

  virtual ~Service();

 protected:

  void send(const void* msg, unsigned int len);
  
  void * createSock(SockType sock_type);

  void stop();

  std::string addr_;

  void* context_;
  
  void* sock_;
};

};

#endif
