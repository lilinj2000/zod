// Copyright (c) 2010
// All rights reserved.

#include "Options.hh"

namespace zod {
namespace proxy {
using soil::json::get_item_value;

Options::Options(
    const rapidjson::Document& doc) {
  get_item_value(&type, doc, "/zod/proxy/type");
  get_item_value(&front_addr, doc, "/zod/proxy/front_addr");
  get_item_value(&backend_addr, doc, "/zod/proxy/backend_addr");
}

};  // namespace proxy

};  // namespace zod
