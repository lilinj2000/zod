// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_SUBSERVICE_HH
#define ZOD_SUBSERVICE_HH

#include <string>
#include "zod/Msg.hh"

namespace zod {

class SubService {
 public:
  virtual ~SubService() {
  }

  static SubService* create(
      const std::string& addr,
      MsgCallback* callback);
};

};  // namespace zod

#endif
