#ifndef ZOD_PUBSERVICE_IMPL_HH
#define ZOD_PUBSERVICE_IMPL_HH

#include "zod/PubService.hh"
#include "Service.hh"

namespace zod
{

class PubServiceImpl : public PubService, public Service
{
 public:
  PubServiceImpl(ServiceType type, const std::string& addr);

  virtual ~PubServiceImpl();

  virtual void sendMsg(const std::string&);

  virtual void sendMsg(const void*, unsigned int);
  
 private:

};


};

#endif
