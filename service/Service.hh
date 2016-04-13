// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_SERVICE_HH
#define ZOD_SERVICE_HH

#include <string>
#include "czmq.h"

namespace zod {

typedef enum {
  PUB_SOCK,
  SUB_SOCK,
  PUSH_SOCK,
  PULL_SOCK
}SockType;

class Service {
 public:
  Service(SockType sock_type,
          const std::string& addr);

  virtual ~Service();

 protected:
  void send(const void* msg, size_t len);

  void send(const std::string& msg);

  zsock_t* createSock(SockType sock_type, const std::string& addr);

  void stop();

  std::string addr_;

  zsock_t* sock_;
};

};  // namespace zod

#endif
