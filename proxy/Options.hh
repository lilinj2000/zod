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

  std::string type;
  std::string frontend;
  std::string backend;
};

}  // namespace proxy

}    // namespace zod
#endif
