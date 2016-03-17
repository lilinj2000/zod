#ifndef ZOD_RECVSERVICE_HH
#define ZOD_RECVSERVICE_HH

#include "Service.hh"
#include <thread>
#include "soil/MsgQueue.hh"

namespace zod
{

class RecvService : public Service
{
 public:

  RecvService(SockType sock_type, const std::string& addr, MsgCallback* callback);

  virtual ~RecvService();

 protected:
  void run();
  
 private:

  MsgCallback* callback_;

  volatile bool is_run_;
  std::unique_ptr<std::thread> recv_thread_;
  std::unique_ptr<soil::MsgQueue<Msg, MsgCallback> > msg_queue_;

};

};

#endif
