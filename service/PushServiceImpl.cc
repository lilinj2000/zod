// Copyright (c) 2010
// All rights reserved.

#include "PushServiceImpl.hh"
#include "soil/Log.hh"

namespace zod {

PushServiceImpl::PushServiceImpl(
    const std::string& addr):
    Service(PUSH_SOCK, addr) {
  SOIL_TRACE("PushServiceImpl::PushServiceImpl()");
}

PushServiceImpl::~PushServiceImpl() {
  SOIL_TRACE("PushServiceImpl::~PushServiceImpl()");
}

void PushServiceImpl::sendMsg(const std::string& msg) {
  SOIL_TRACE("PushServiceImpl::sendMsg()");

  send(msg);
}

void PushServiceImpl::sendMsg(const void* msg, size_t len) {
  SOIL_TRACE("PushServiceImpl::sendMsg()");

  send(msg, len);
}

PushService* PushService::create(const std::string& addr) {
  return new PushServiceImpl(addr);
}

};  // namespace zod
