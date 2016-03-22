// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "Server.hh"
#include "Config.hh"

int main(int argc, char* argv[]) {
  std::unique_ptr<bus::Config> config(new bus::Config(argc, argv));

  std::unique_ptr<bus::Server> bus(new bus::Server(config->options()));
}
