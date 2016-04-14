// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "Server.hh"
#include "Config.hh"
#include "soil/Pause.hh"

int main(int argc, char* argv[]) {
  std::unique_ptr<proxy::Config> config
  (new proxy::Config(argc, argv));

  std::unique_ptr<proxy::Server> proxy
  (new proxy::Server(config->options()));

  std::unique_ptr<soil::Pause> pause(soil::Pause::create());
}
