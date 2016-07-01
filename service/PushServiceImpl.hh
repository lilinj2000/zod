// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PUSHSERVICE_IMPL_HH
#define ZOD_PUSHSERVICE_IMPL_HH

#include <string>
#include "zod/PushService.hh"
#include "Service.hh"

namespace zod {

class PushServiceImpl : public PushService, public Service {
 public:
  explicit PushServiceImpl(const std::string& addr);

  virtual ~PushServiceImpl();

  virtual void sendMsg(const std::string&);

  virtual void sendMsg(const void*, size_t);
};


};  // namespace zod

#endif
