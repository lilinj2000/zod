// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "gtest/gtest.h"
#include "zod/PullService.hh"
#include "soil/STimer.hh"

namespace zod {

class PullServiceTest : public ::testing::Test, public MsgCallback {
 public:
  PullServiceTest():
      pull_addr(">tcp://127.0.0.1:9991") {
  }

  virtual void msgCallback(const Msg* msg) {
  }

 protected:
  std::string pull_addr;
};

TEST_F(PullServiceTest, createTest) {
  std::unique_ptr<PullService> pull_service;

  pull_service.reset(PullService::create(pull_addr, this));

  std::unique_ptr<soil::STimer> cond(soil::STimer::create());
  cond->wait(200);

  GTEST_SUCCEED();
}

}  // namespace zod
