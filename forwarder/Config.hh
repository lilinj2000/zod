// Copyright (c) 2010
// All rights reserved.

#ifndef FORWARDER_CONFIG_HH
#define FORWARDER_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace forwarder {

namespace po = boost::program_options;

class Options : public soil::Options {
 public:
  Options();

  virtual ~Options();

  virtual po::options_description* configOptions();

  std::string xsub_addr;

  std::string xpub_addr;

  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class Config {
 public:
  explicit Config(int argc = 0, char* argv[] = nullptr);
  ~Config();

  Options* options() {
    return options_.get();
  }

 private:
  std::unique_ptr<Options> options_;
};

}  // namespace forwarder

#endif
