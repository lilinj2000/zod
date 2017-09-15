// Copyright (c) 2010
// All rights reserved.

#include "PubServiceImpl.hh"
#include "soil/Log.hh"

namespace zod {

PubServiceImpl::PubServiceImpl(const std::string& addr):
    Service(PUB_SOCK, addr) {
  SOIL_TRACE("PubServiceImpl::PubServiceImpl()");
}

PubServiceImpl::~PubServiceImpl() {
  SOIL_TRACE("PubServiceImpl::~PubServiceImpl()");
}

void PubServiceImpl::sendMsg(const std::string& msg) {
  SOIL_TRACE("PubServiceImpl::sendMsg()");

  send(msg);
}

void PubServiceImpl::sendMsg(const void* msg, size_t len) {
  SOIL_TRACE("PubServiceImpl::sendMsg()");

  send(msg, len);
}

PubService* PubService::create(const std::string& addr){
  return new PubServiceImpl(addr);
}

};  // namespace zod
