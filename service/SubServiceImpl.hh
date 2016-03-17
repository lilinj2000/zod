#ifndef ZOD_SUBSERVICE_IMPL_HH
#define ZOD_SUBSERVICE_IMPL_HH

#include "zod/SubService.hh"
#include "RecvService.hh"


namespace zod
{

class SubServiceImpl : public SubService, public RecvService
{
 public:
  SubServiceImpl(const std::string& addr, MsgCallback* callback);

  virtual ~SubServiceImpl();
};


};

#endif
