// Copyright (c) 2010
// All rights reserved.

#include <zmq.h>
#include <cassert>
#include "Server.hh"
#include "Config.hh"
#include "Log.hh"

namespace bus {

Server::Server(Options* options):
    options_(options),
    context_(nullptr),
    router_(nullptr),
    dealer_(nullptr) {
  BUS_TRACE <<"Server::Server()";

  context_ = zmq_ctx_new();
  assert(context_);

  router_ = zmq_socket(context_, ZMQ_ROUTER);
  assert(router_);

  dealer_ = zmq_socket(context_, ZMQ_DEALER);
  assert(dealer_);

  BUS_INFO <<"router_addr: " <<options_->router_addr;
  if ( zmq_bind(router_, options_->router_addr.data()) < 0 ) {
    std::string err = "router bind error.\n";
    throw std::runtime_error(err+zmq_strerror(zmq_errno()));
  }

  BUS_INFO <<"dealer_addr: " <<options_->dealer_addr;
  if ( zmq_bind(dealer_, options_->dealer_addr.data()) < 0 ) {
    std::string err = "dealer bind error.\n";
    throw std::runtime_error(err+zmq_strerror(zmq_errno()));
  }

  zmq_proxy(router_, dealer_, nullptr);
}

Server::~Server() {
  BUS_TRACE <<"Server::~Server()";

  zmq_close(router_);
  zmq_close(dealer_);

  zmq_ctx_destroy(context_);
}

};  // namespace bus
