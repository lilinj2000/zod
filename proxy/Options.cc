// Copyright (c) 2010
// All rights reserved.

#include "Options.hh"

namespace zod {
namespace proxy {
using soil::json::get_item_value;

Options::Options(
    const rapidjson::Document& doc) {
  get_item_value(&type, doc, "/zod/proxy/type");
  get_item_value(&frontend, doc, "/zod/proxy/frontend");
  get_item_value(&backend, doc, "/zod/proxy/backend");
}

};  // namespace proxy

};  // namespace zod
