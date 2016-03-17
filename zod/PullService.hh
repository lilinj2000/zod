#ifndef ZOD_PULLSERVICE_HH
#define ZOD_PULLSERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod
{

class PullService
{
 public:

  virtual ~PullService() {
  }

  static PullService* create(const std::string& addr, MsgCallback* callback);
  
};


};

#endif