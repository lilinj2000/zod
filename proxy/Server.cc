// Copyright (c) 2010
// All rights reserved.

#include <cassert>
#include "Server.hh"
#include "Options.hh"
#include "soil/Log.hh"

namespace zod {
namespace proxy {

Server::Server(
    const rapidjson::Document& doc) :
    proxy_(nullptr) {
  SOIL_TRACE("Server::Server()");

  options_.reset(new Options(doc));

  proxy_ = zactor_new(zproxy, nullptr);
  assert(proxy_);

  initProxy(options_->type);
}

Server::~Server() {
  SOIL_TRACE("Server::~Server()");

  zactor_destroy(&proxy_);
}

void Server::initProxy(int type) {
  SOIL_TRACE("Server::initProxy()");

  std::string front_sock;
  std::string backend_sock;
  switch (type) {
    case 1:  // forwarder
      SOIL_INFO("=== proxy forwarder ===");
      front_sock = "XSUB";
      backend_sock = "XPUB";
      break;

    case 2:  // streamer
      SOIL_INFO("=== proxy streamer ===");
      front_sock = "PULL";
      backend_sock = "PUSH";
      break;

    case 3:  // bus
      SOIL_INFO("=== proxy bus ===");
      front_sock = "ROUTER";
      backend_sock = "DEALER";
      break;

    default:
      throw std::runtime_error("invalid proxy type.");
  }

  SOIL_DEBUG("=== front addr - {}", options_->front_addr);
  zstr_sendx(proxy_, "FRONTEND", front_sock.data(),
             options_->front_addr.data(), nullptr);
  zsock_wait(proxy_);

  SOIL_DEBUG("=== backend addr - {}", options_->backend_addr);
  zstr_sendx(proxy_, "BACKEND", backend_sock.data(),
             options_->backend_addr.data(), nullptr);
  zsock_wait(proxy_);
}

};  // namespace proxy

};    // namespace zod
