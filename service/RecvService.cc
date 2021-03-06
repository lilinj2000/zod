// Copyright (c) 2010
// All rights reserved.

#include <czmq.h>
#include "RecvService.hh"
#include "soil/Log.hh"

namespace zod {

RecvService::RecvService(
    SockType sock_type,
    const std::string& addr,
    MsgCallback* callback):
    Service(sock_type, addr),
    callback_(callback),
    is_run_(false),
    poller_(nullptr) {
  SOIL_TRACE("RecvService::RecvService()");

  queue_.reset(new soil::ReaderWriterQueue<Msg>(callback_));

  poller_ = zpoller_new(sock_, nullptr);
  assert(poller_);

  is_run_ = true;
  recv_thread_.reset(new std::thread(&RecvService::run, this));
}

RecvService::~RecvService() {
  SOIL_TRACE("RecvService::~RecvService()");

  is_run_ = false;
  recv_thread_->join();

  zpoller_remove(poller_, sock_);
  zpoller_destroy(&poller_);
  poller_ = nullptr;
}


void RecvService::run() {
  SOIL_TRACE("RecvService::run()");

  while (is_run_) {
    // wait 1 second
    zsock_t* which = static_cast<zsock_t *>(
        zpoller_wait(
            poller_, 1000));
    if (!which) {
      continue;
    }

    zmsg_t* zmsg = zmsg_recv(which);
    if (nullptr == zmsg) {
      SOIL_ERROR("recv msg failed.\n {}",
                 zmq_strerror(zmq_errno()));
    } else {
      zframe_t* frame = zmsg_pop(zmsg);

      if (frame) {
        std::shared_ptr<Msg> data(
            new Msg(
                zframe_data(frame),
                zframe_size(frame)));
        queue_->pushMsg(data);

        zframe_destroy(&frame);
      }
      zmsg_destroy(&zmsg);
    }
  }

  SOIL_DEBUG("RecvServiceImpl::run()  done.");
}

};  // namespace zod
