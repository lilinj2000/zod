// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include <thread>
#include "gtest/gtest.h"
#include "zod/SubService.hh"
#include "zod/PubService.hh"
#include "soil/STimer.hh"
#include "soil/Log.hh"
#include "soil/hexdump.hh"

namespace zod {

class SubServiceTest :
      public ::testing::Test,
      public MsgCallback {
 public:
  SubServiceTest():
      addr("tcp://127.0.0.1:9991") {
    rapidjson::Document doc;
    soil::json::load_from_file(&doc, "log.json");
    soil::log::init(doc);

    sub_service.reset(SubService::create(addr, this));
    pub_service.reset(PubService::create(addr));
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
  std::unique_ptr<SubService> sub_service;
  std::unique_ptr<PubService> pub_service;
};

TEST_F(SubServiceTest, createTest) {
  sub_service->setSubscribe("Hello");
  std::this_thread::sleep_for(
      std::chrono::seconds(1));

  for (int i = 0; i < 10; ++i) {
    pub_service->sendMsg("Hello world!");
  }

  sub_service->setUnsubscribe("Hello");
  std::this_thread::sleep_for(
      std::chrono::seconds(1));

  for (int i = 0; i < 10; ++i) {
    pub_service->sendMsg("Hello world!");
  }

  std::this_thread::sleep_for(
      std::chrono::seconds(2));
  SUCCEED();
}

}  // namespace zod
