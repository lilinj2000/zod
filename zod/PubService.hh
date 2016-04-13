// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PUBSERVICE_HH
#define ZOD_PUBSERVICE_HH

#include <string>
#include "zod/ZodDef.hh"

namespace zod {

class PubService {
 public:
  virtual ~PubService() {
  }

  virtual void sendMsg(const std::string&) = 0;

  virtual void sendMsg(const void*, size_t) = 0;

  static PubService* create(const std::string& addr);
};

};  // namespace zod

#endif
