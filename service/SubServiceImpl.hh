// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_SUBSERVICE_IMPL_HH
#define ZOD_SUBSERVICE_IMPL_HH

#include <string>
#include "zod/SubService.hh"
#include "RecvService.hh"

namespace zod {

class SubServiceImpl :
      public SubService,
      public RecvService {
 public:
  SubServiceImpl(
      const std::string& addr,
      MsgCallback* callback);

  virtual void setSubscribe(
      const std::string&);

  virtual void setUnsubscribe(
      const std::string&);

  virtual ~SubServiceImpl();
};


};  // namespace zod

#endif
