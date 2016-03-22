// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include "Config.hh"
#include "Log.hh"

namespace streamer {

Options::Options():
    config_options_("StreamerOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("streamer.pull_addr", po::value<std::string>(&pull_addr),
       "pull address")
      ("streamer.push_addr", po::value<std::string>(&push_addr),
       "push address")

      ("streamer.log_cfg", po::value<std::string>(&log_cfg),
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

  config->configFile() = "streamer.cfg";
  config->loadConfig(argc, argv);

  // init the log
  STREAMER_LOG_INIT(options_->log_cfg);

  return;
}

Config::~Config() {
}

};  // namespace streamer
