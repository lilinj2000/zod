// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PUBSERVICE_IMPL_HH
#define ZOD_PUBSERVICE_IMPL_HH

#include <string>
#include "zod/PubService.hh"
#include "Service.hh"

namespace zod {

class PubServiceImpl : public PubService, public Service {
 public:
  explicit PubServiceImpl(const std::string& addr);

  virtual ~PubServiceImpl();

  virtual void sendMsg(const std::string&);

  virtual void sendMsg(const void*, size_t);
};

};  // namespace zod

#endif
