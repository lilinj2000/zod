#ifndef ZOD_SUBSERVICE_IMPL_HH
#define ZOD_SUBSERVICE_IMPL_HH

#include "zod/SubService.hh"

#include <thread>
#include "soil/MsgQueue.hh"

namespace zod
{

class SubServiceImpl : public SubService
{
 public:
  SubServiceImpl(const std::string& addr, MsgCallback* callback);

  virtual ~SubServiceImpl();

 protected:

  void run();
  
 private:

  std::string addr_;

  MsgCallback* callback_;

  void* context_;
  void* sub_;

  volatile bool is_run_;
  std::unique_ptr<std::thread> recv_thread_;
  std::unique_ptr<soil::MsgQueue<Msg, MsgCallback> > msg_queue_;

};


};

#endif
