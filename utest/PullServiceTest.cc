// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include <thread>
#include "gtest/gtest.h"
#include "zod/PullService.hh"
#include "zod/PushService.hh"
#include "soil/STimer.hh"
#include "soil/Log.hh"
#include "soil/hexdump.hh"

namespace zod {

class PullServiceTest :
      public ::testing::Test,
      public MsgCallback {
 public:
  PullServiceTest():
      addr("tcp://127.0.0.1:9991") {
    rapidjson::Document doc;
    soil::json::load_from_file(&doc, "log.json");
    soil::log::init(doc);

    pull_service.reset(PullService::create(addr, this));
    push_service.reset(PushService::create(addr));
  }

  virtual void msgCallback(
      std::shared_ptr<Msg> msg) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG("{}",
               soil::hexdump("receive msg",
                             msg->data(),
                             msg->len()));
  }

 protected:
  std::string addr;
  std::unique_ptr<PushService> push_service;
  std::unique_ptr<PullService> pull_service;
};

TEST_F(PullServiceTest, createTest) {
  for (int i = 0; i < 10; ++i) {
    push_service->sendMsg("Hello world!");
  }

  std::this_thread::sleep_for(
      std::chrono::seconds(2));
  SUCCEED();
}

}  // namespace zod
