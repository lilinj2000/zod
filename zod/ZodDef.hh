// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_DEF_HH
#define ZOD_DEF_HH

#include <memory>
#include <cstring>

namespace zod {

class Msg {
 public:
  Msg(const void* data, unsigned int len):
      len_(len) {
    data_.reset( new unsigned char[len_] );

    std::memcpy(data_.get(), data, len_);
  }

  virtual ~Msg() {
  }

  std::unique_ptr<unsigned char> data_;

  unsigned int len_;
};

class MsgCallback {
 public:
  virtual ~MsgCallback() {
  }

  virtual void msgCallback(const Msg*) = 0;
};

};  // namespace zod

#endif
