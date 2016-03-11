#ifndef ZOD_PUBSERVICE_HH
#define ZOD_PUBSERVICE_HH

#include "zod/ZodDef.hh"

namespace zod
{

class PubService
{
 public:

  virtual ~PubService() {
  }

  static PubService* createService(const std::string& addr, ServiceType type=BIND);
  
}
};

#endif
