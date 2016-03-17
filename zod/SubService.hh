#ifndef ZOD_SUBSERVICE_HH
#define ZOD_SUBSERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod
{

class SubService
{
 public:

  virtual ~SubService() {
  }

  static SubService* create(const std::string& addr, MsgCallback* callback);
  
};


};

#endif
