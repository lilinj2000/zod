// Copyright (c) 2010
// All rights reserved.

#include "PubServiceImpl.hh"
#include "Log.hh"

namespace zod {

PubServiceImpl::PubServiceImpl(const std::string& addr):
    Service(PUB_SOCK, addr) {
  ZOD_TRACE <<"PubServiceImpl::PubServiceImpl()";
}

PubServiceImpl::~PubServiceImpl() {
  ZOD_TRACE <<"PubServiceImpl::~PubServiceImpl()";
}

void PubServiceImpl::sendMsg(const std::string& msg) {
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  send(msg);
}

void PubServiceImpl::sendMsg(const void* msg, size_t len) {
  ZOD_TRACE <<"PubServiceImpl::sendMsg()";

  send(msg, len);
}

PubService* PubService::create(const std::string& addr){
  return new PubServiceImpl(addr);
}

};  // namespace zod
