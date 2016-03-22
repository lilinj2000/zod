// Copyright (c) 2010
// All rights reserved.

#include "PushServiceImpl.hh"
#include "Log.hh"

namespace zod {

PushServiceImpl::PushServiceImpl(ServiceType type, const std::string& addr):
    Service(PUSH_SOCK, type, addr) {
  ZOD_TRACE <<"PushServiceImpl::PushServiceImpl()";
}

PushServiceImpl::~PushServiceImpl() {
  ZOD_TRACE <<"PushServiceImpl::~PushServiceImpl()";
}

void PushServiceImpl::sendMsg(const std::string& msg) {
  ZOD_TRACE <<"PushServiceImpl::sendMsg()";

  send(msg.data(), msg.length()+1);
}

void PushServiceImpl::sendMsg(const void* msg, unsigned int len) {
  ZOD_TRACE <<"PushServiceImpl::sendMsg()";

  send(msg, len);
}

PushService* PushService::create(const std::string& addr, ServiceType type) {
  return new PushServiceImpl(type, addr);
}

};  // namespace zod
