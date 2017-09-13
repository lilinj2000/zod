// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_PROXY_OPTIONS_HH
#define ZOD_PROXY_OPTIONS_HH

#include <string>
#include "soil/json.hh"

namespace zod {
namespace proxy {
class Options {
 public:
  explicit Options(
      const rapidjson::Document& doc);

  virtual ~Options() {
  }

  int type;
  std::string front_addr;
  std::string backend_addr;
};

}  // namespace proxy

}    // namespace zod
#endif
