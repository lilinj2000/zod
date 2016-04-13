// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include "Config.hh"
#include "Log.hh"

namespace proxy {

Options::Options():
    config_options_("ProxyOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("proxy.type", po::value<int>(&type),
       "type")

      ("proxy.front_addr", po::value<std::string>(&front_addr),
       "front address")
      ("proxy.backend_addr", po::value<std::string>(&backend_addr),
       "backend address")

      ("proxy.log_cfg", po::value<std::string>(&log_cfg),
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

  config->configFile() = "proxy.cfg";
  config->loadConfig(argc, argv);

  // init the log
  PROXY_LOG_INIT(options_->log_cfg);

  return;
}

Config::~Config() {
}

};  // namespace proxy
