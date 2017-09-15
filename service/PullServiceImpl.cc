// Copyright (c) 2010
// All rights reserved.

#include <zmq.h>
#include "PullServiceImpl.hh"
#include "soil/Log.hh"

namespace zod {

PullServiceImpl::PullServiceImpl(
    const std::string& addr,
    MsgCallback* callback):
    RecvService(PULL_SOCK, addr, callback) {
  SOIL_TRACE("PullServiceImpl::PullServiceImpl()");
}

PullServiceImpl::~PullServiceImpl() {
  SOIL_TRACE("PullServiceImpl::~PullServiceImpl()");
}

PullService* PullService::create(
    const std::string& addr,
    MsgCallback* callback) {
  return new PullServiceImpl(addr, callback);
}

};  // namespace zod
