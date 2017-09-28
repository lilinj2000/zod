// Copyright (c) 2010
// All rights reserved.

#include <zmq.h>
#include "SubServiceImpl.hh"
#include "soil/Log.hh"

namespace zod {

SubServiceImpl::SubServiceImpl(
    const std::string& addr,
    MsgCallback* callback):
    RecvService(SUB_SOCK, addr, callback) {
  SOIL_TRACE("SubServiceImpl::SubServiceImpl()");
}

void SubServiceImpl::setSubscribe(
    const std::string& subscribe) {
  zsock_set_subscribe(sock_, subscribe.c_str());
}

void SubServiceImpl::setUnsubscribe(
    const std::string& subscribe) {
  zsock_set_unsubscribe(sock_, subscribe.c_str());
}

SubServiceImpl::~SubServiceImpl() {
  SOIL_TRACE("SubServiceImpl::~SubServiceImpl()");
}

SubService* SubService::create(
    const std::string& addr,
    MsgCallback* callback) {
  return new SubServiceImpl(addr, callback);
}

};  // namespace zod
