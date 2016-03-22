// Copyright (c) 2010
// All rights reserved.

#include <zmq.h>
#include <cassert>
#include "Server.hh"
#include "Config.hh"
#include "Log.hh"


namespace streamer {

Server::Server(Options* options):
    options_(options),
    context_(nullptr),
    pull_(nullptr),
    push_(nullptr) {
  STREAMER_TRACE <<"Server::Server()";

  context_ = zmq_ctx_new();
  assert(context_);

  pull_ = zmq_socket(context_, ZMQ_PULL);
  assert(pull_);

  push_ = zmq_socket(context_, ZMQ_PUSH);
  assert(push_);

  STREAMER_INFO <<"pull_addr: " <<options_->pull_addr;
  if ( zmq_bind(pull_, options_->pull_addr.data()) < 0 ) {
    std::string err = "pull bind error.\n";
    throw std::runtime_error(err+zmq_strerror(zmq_errno()));
  }

  STREAMER_INFO <<"push_addr: " <<options_->push_addr;
  if ( zmq_bind(push_, options_->push_addr.data()) < 0 ) {
    std::string err = "push bind error.\n";
    throw std::runtime_error(err+zmq_strerror(zmq_errno()));
  }

  zmq_proxy(pull_, push_, nullptr);
}

Server::~Server() {
  STREAMER_TRACE <<"Server::~Server()";

  zmq_close(pull_);
  zmq_close(push_);

  zmq_ctx_destroy(context_);
}

};  // namespace streamer
