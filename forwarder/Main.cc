// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "Server.hh"
#include "Config.hh"

int main(int argc, char* argv[]) {
  std::unique_ptr<forwarder::Config> config
  (new forwarder::Config(argc, argv));

  std::unique_ptr<forwarder::Server> forwarder
  (new forwarder::Server(config->options()));
}
