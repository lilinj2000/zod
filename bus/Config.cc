// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include "Config.hh"
#include "Log.hh"

namespace bus {

Options::Options():
    config_options_("BusOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("bus.router_addr", po::value<std::string>(&router_addr),
       "router address")
      ("bus.dealer_addr", po::value<std::string>(&dealer_addr),
       "dealer address")

      ("bus.log_cfg", po::value<std::string>(&log_cfg),
       "log config file");

  return;
}

Options::~Options() {
}

po::options_description* Options::configOptions() {
  return &config_options_;
}

Config::Config(int argc, char* argv[]) {
  options_.reset(new Options());

  std::auto_ptr<soil::Config> config(soil::Config::create());
  config->registerOptions(options_.get());

  config->configFile() = "bus.cfg";
  config->loadConfig(argc, argv);

  // init the log
  BUS_LOG_INIT(options_->log_cfg);

  return;
}

Config::~Config() {
}

};  // namespace bus
