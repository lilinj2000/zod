// Copyright (c) 2010
// All rights reserved.

#ifndef BUS_SERVER_HH
#define BUS_SERVER_HH

namespace bus {

class Options;

class Server {
 public:
  explicit Server(Options* options);

  virtual ~Server();

 private:
  Options* options_;

  void* context_;
  void* router_;
  void* dealer_;
};


};  // namespace bus

#endif
