// Copyright (c) 2010
// All rights reserved.

#include <cassert>
#include "Server.hh"
#include "Config.hh"
#include "Log.hh"

namespace proxy {

Server::Server(Options* options):
    options_(options),
    proxy_(nullptr) {
  PROXY_TRACE <<"Server::Server()";

  proxy_ = zactor_new(zproxy, nullptr);
  assert(proxy_);

  initProxy(options_->type);
}

Server::~Server() {
  PROXY_TRACE <<"Server::~Server()";

  zactor_destroy(&proxy_);
}

void Server::initProxy(int type) {
  PROXY_TRACE <<"Server::initProxy()";

  std::string front_sock;
  std::string backend_sock;
  switch (type) {
    case 1:  // forwarder
      front_sock = "XSUB";
      backend_sock = "XPUB";
      break;

    case 2:  // streamer
      front_sock = "PULL";
      backend_sock = "PUSH";
      break;

    case 3:  // bus
      front_sock = "ROUTER";
      backend_sock = "DEALER";
      break;

    default:
      throw std::runtime_error("invalid proxy type.");
  }
  
  zstr_sendx(proxy_, "FRONTEND", front_sock.data(), options_->front_addr.data(), nullptr);
  zsock_wait(proxy_);

  zstr_sendx(proxy_, "BACKEND", backend_sock.data(), options_->backend_addr.data(), nullptr);
  zsock_wait(proxy_);

}

};  // namespace proxy
