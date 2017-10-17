// Copyright (c) 2010
// All rights reserved.

#ifndef ZOD_MSG_HH
#define ZOD_MSG_HH

#include <memory>
#include <cstring>
#include "soil/ReaderWriterQueue.hh"

namespace zod {

class Msg {
 public:
  Msg(const void* data, unsigned int len):
      len_(len) {
    data_.reset(new unsigned char[len_]);

    std::memcpy(data_.get(), data, len_);
  }

  virtual ~Msg() {
  }

  const unsigned char* data() {
    return data_.get();
  }

  unsigned int len() {
    return len_;
  }

 private:
  std::unique_ptr<unsigned char> data_;

  unsigned int len_;
};

class MsgCallback :
      public soil::MsgCallback<Msg> {
 public:
  virtual ~MsgCallback() {
  }

  virtual void onMsg(
      std::shared_ptr<Msg> msg) = 0;

  virtual void onStart() = 0;

  virtual void onStop() = 0;
};

};  // namespace zod

#endif
