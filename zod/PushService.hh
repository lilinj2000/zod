// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PUSHSERVICE_HH
#define ZOD_PUSHSERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod {

class PushService {
 public:
  virtual ~PushService() {
  }

  virtual void sendMsg(const std::string&) = 0;

  virtual void sendMsg(const void*, size_t) = 0;

  static PushService* create(const std::string& addr);
};

};  // namespace zod

#endif
