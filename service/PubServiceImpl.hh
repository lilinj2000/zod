#ifndef ZOD_PUBSERVICE_IMPL_HH
#define ZOD_PUBSERVICE_IMPL_HH

#include "zod/PubService.hh"

namespace zod
{

class PubServiceImpl : public PubService
{
 public:
  PubServiceImpl(ServiceType type, const std::string& addr);

  virtual ~PubServiceImpl();

  virtual void sendMsg(const std::string&);

  virtual void sendMsg(void*, unsigned int);
  
 private:

  std::string addr_;

  void* context_;
  void* pub_;

};


};

#endif
