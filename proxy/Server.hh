// Copyright (c) 2010
// All rights reserved.

#ifndef PROXY_SERVER_HH
#define PROXY_SERVER_HH

#include <czmq.h>

namespace proxy {

class Options;

class Server {
 public:
  explicit Server(Options* options);

  virtual ~Server();

 private:
  void initProxy(int type);

  Options* options_;

  zactor_t* proxy_;
};

};  // namespace proxy

#endif
