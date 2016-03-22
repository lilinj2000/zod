// Copyright (c) 2010
// All rights reserved.

#include "PubServiceImpl.hh"
#include "Log.hh"

namespace zod {

PubServiceImpl::PubServiceImpl(ServiceType type, const std::string& addr):
    Service(PUB_SOCK, type, addr) {
  ZOD_TRACE <<"PubServiceImpl::PubServiceImpl()";
}

PubServiceImpl::~PubServiceImpl() {
  ZOD_TRACE <<"PubServiceImpl::~PubServiceImpl()";
}

void PubServiceImpl::sendMsg(const std::string& msg) {
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  send(msg.data(), msg.length()+1);
}

void PubServiceImpl::sendMsg(const void* msg, unsigned int len) {
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  send(msg, len);
}

PubService* PubService::create(const std::string& addr, ServiceType type){
  return new PubServiceImpl(type, addr);
}

};  // namespace zod
