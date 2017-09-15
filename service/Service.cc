// Copyright (c) 2010
// All rights reserved.

#include "Service.hh"
#include "soil/Log.hh"

namespace zod {

Service::Service(SockType sock_type,
                 const std::string& addr):
    addr_(addr),
    sock_(nullptr) {
  SOIL_TRACE("Service::Service()");

  sock_ = createSock(sock_type, addr_);
  assert(sock_);
}

Service::~Service() {
  SOIL_TRACE("Service::~Service()");

  stop();
}

void Service::send(const void* msg, size_t len) {
  SOIL_TRACE("Service::send()");

  zmsg_t* zmsg = zmsg_new();
  zmsg_addmem(zmsg, msg, len);

  if (zmsg_send(&zmsg, sock_) < 0) {
    SOIL_ERROR("msg send failed.\n"
               "{}", zmq_strerror(zmq_errno()));
  }
}

void Service::send(const std::string& msg) {
  SOIL_TRACE("Service::send()");

  zmsg_t* zmsg = zmsg_new();
  zmsg_addstr(zmsg, msg.data());

  if (zmsg_send(&zmsg, sock_) < 0) {
    SOIL_ERROR("msg send failed.\n"
               "{}", zmq_strerror(zmq_errno()));
  }
}

void Service::stop() {
  SOIL_TRACE("Service::stop()");

  if (sock_) {
    zsock_destroy(&sock_);
    sock_ = nullptr;
  }
}

zsock_t* Service::createSock(
    SockType sock_type,
    const std::string& addr) {
  zsock_t* sock = nullptr;

  switch (sock_type) {
    case PUB_SOCK:
      sock = zsock_new_pub(addr.data());
      break;

    case SUB_SOCK:
      sock = zsock_new_sub(addr.data(), "");
      break;

    case PUSH_SOCK:
      sock = zsock_new_push(addr.data());
      break;

    case PULL_SOCK:
      sock = zsock_new_pull(addr.data());
      break;
  }

  return sock;
}

};  // namespace zod
