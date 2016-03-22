// Copyright (c) 2010
// All rights reserved.

#ifndef STREAMER_SERVER_HH
#define STREAMER_SERVER_HH

namespace streamer {

class Options;

class Server {
 public:
  explicit Server(Options* options);

  virtual ~Server();

 private:
  Options* options_;

  void* context_;
  void* pull_;
  void* push_;
};


};  // namespace streamer

#endif
