#ifndef ZOD_PUSHSERVICE_HH
#define ZOD_PUSHSERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod
{

class PushService
{
 public:

  virtual ~PushService() {
  }

  virtual void sendMsg(const std::string&) = 0;

  virtual void sendMsg(const void*, unsigned int) = 0;

  static PushService* create(const std::string& addr, ServiceType type=BIND);
  
};


};

#endif