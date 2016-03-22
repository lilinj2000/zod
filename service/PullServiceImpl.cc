// Copyright (c) 2010
// All rights reserved.

#include <zmq.h>
#include "PullServiceImpl.hh"
#include "Log.hh"

namespace zod {

PullServiceImpl::PullServiceImpl(const std::string& addr,
                                   MsgCallback* callback):
    RecvService(PULL_SOCK, addr, callback) {
  ZOD_TRACE <<"PullServiceImpl::PullServiceImpl()";
}

PullServiceImpl::~PullServiceImpl() {
  ZOD_TRACE <<"PullServiceImpl::~PullServiceImpl()";
}

PullService* PullService::create(const std::string& addr,
                                   MsgCallback* callback) {
  return new PullServiceImpl(addr, callback);
}

};  // namespace zod
