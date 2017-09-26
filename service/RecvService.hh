// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_RECVSERVICE_HH
#define ZOD_RECVSERVICE_HH

#include <thread>
#include <string>
#include "Service.hh"
#include "zod/Msg.hh"
#include "soil/ReaderWriterQueue.hh"

namespace zod {

class RecvService :
      public Service {
 public:
  RecvService(
      SockType sock_type,
      const std::string& addr,
      MsgCallback* callback);

  virtual ~RecvService();

 protected:
  void run();

 private:
  MsgCallback* callback_;

  volatile bool is_run_;
  std::unique_ptr<std::thread> recv_thread_;
  std::unique_ptr<soil::ReaderWriterQueue<Msg> > queue_;

  zpoller_t* poller_;
};

};  // namespace zod

#endif
