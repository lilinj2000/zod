// Copyright (c) 2010
// All rights reserved.

#ifndef PROXY_CONFIG_HH
#define PROXY_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace proxy {

namespace po = boost::program_options;

class Options : public soil::Options {
 public:
  Options();

  virtual ~Options();

  virtual po::options_description* configOptions();

  int type;
  std::string front_addr;
  std::string backend_addr;
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

}  // namespace proxy

#endif
