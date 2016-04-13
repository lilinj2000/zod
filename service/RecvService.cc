// Copyright (c) 2010
// All rights reserved.

#include "czmq.h"
#include "RecvService.hh"
#include "Log.hh"

namespace zod {

RecvService::RecvService(SockType sock_type, const std::string& addr,
                           MsgCallback* callback):
    Service(sock_type, addr),
    callback_(callback),
    is_run_(false) {
  ZOD_TRACE <<"RecvService::RecvService()";

  msg_queue_.reset(new soil::MsgQueue<Msg, MsgCallback>(callback_));

  is_run_ = true;
  recv_thread_.reset(new std::thread(&RecvService::run, this));
}

RecvService::~RecvService() {
  ZOD_TRACE <<"RecvService::~RecvService()";

  is_run_ = false;

  stop();

  recv_thread_->join();
}


void RecvService::run() {
  ZOD_TRACE <<"RecvService::run()";

  while (is_run_) {
    zmsg_t* zmsg = zmsg_recv(sock_);
    if (nullptr == zmsg) {
      ZOD_ERROR <<"recv msg failed.\n"
                 <<zmq_strerror(zmq_errno());
    } else {
      zframe_t* frame = zmsg_pop(zmsg);

      if (frame) {
        std::unique_ptr<Msg> data(new Msg(zframe_data(frame),
                                          zframe_size(frame)));
        msg_queue_->pushMsg(data.release());

        zframe_destroy(&frame);
      }
      zmsg_destroy(&zmsg);
    }
  }

  ZOD_DEBUG <<"RecvServiceImpl::run()  done.";
}

};  // namespace zod
