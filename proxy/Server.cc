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

  if (options_->type == "Forwarder") {
    forwarderProxy();
  } else if (options_->type == "Streamer") {
    streamerProxy();
  } else if (options_->type == "SharedQueue") {
    sharedQueueProxy();
  }
}

Server::~Server() {
  SOIL_TRACE("Server::~Server()");

  zactor_destroy(&proxy_);
}

void Server::forwarderProxy() {
  SOIL_TRACE("Server::forwarderProxy()");

  zstr_sendx(proxy_, "FRONTEND", "XSUB",
             options_->frontend.data(), nullptr);
  zsock_wait(proxy_);
  zstr_sendx(proxy_, "BACKEND", "XPUB",
             options_->backend.data(), nullptr);
  zsock_wait(proxy_);
}

void Server::streamerProxy() {
  SOIL_TRACE("Server::streamerProxy()");

  zstr_sendx(proxy_, "FRONTEND", "PULL",
             options_->frontend.data(), nullptr);
  zsock_wait(proxy_);
  zstr_sendx(proxy_, "BACKEND", "PUSH",
             options_->backend.data(), nullptr);
  zsock_wait(proxy_);
}

void Server::sharedQueueProxy() {
  SOIL_TRACE("Server::sharedQueueProxy()");

  zstr_sendx(proxy_, "FRONTEND", "ROUTE",
             options_->frontend.data(), nullptr);
  zsock_wait(proxy_);
  zstr_sendx(proxy_, "BACKEND", "DEALER",
             options_->backend.data(), nullptr);
  zsock_wait(proxy_);
}

};  // namespace proxy

};    // namespace zod
