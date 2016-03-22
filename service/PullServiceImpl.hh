// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PULLSERVICE_IMPL_HH
#define ZOD_PULLSERVICE_IMPL_HH

#include <string>
#include "zod/PullService.hh"
#include "RecvService.hh"

namespace zod {

class PullServiceImpl : public PullService, public RecvService {
 public:
  PullServiceImpl(const std::string& addr, MsgCallback* callback);

  virtual ~PullServiceImpl();
};


};  // namespace zod

#endif
