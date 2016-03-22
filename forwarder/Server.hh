// Copyright (c) 2010
// All rights reserved.

#ifndef FORWARDER_SERVER_HH
#define FORWARDER_SERVER_HH

namespace forwarder {

class Options;

class Server {
 public:
  explicit Server(Options* options);

  virtual ~Server();

 private:
  Options* options_;

  void* context_;
  void* xsub_;
  void* xpub_;
};

};  // namespace forwarder

#endif
