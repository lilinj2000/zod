#include "Config.hh"
#include "Log.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace forwarder
{

Options::Options():
    config_options_("ForwarderOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("forwarder.xsub_addr", po::value<std::string>(&xsub_addr), 
       "xsub address")
      ("forwarder.xpub_addr", po::value<std::string>(&xpub_addr), 
       "xpub address")

      ("forwarder.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

Options::~Options()
{
}

po::options_description* Options::configOptions()
{
  return &config_options_;
}

Config::Config(int argc, char* argv[])
{
  options_.reset(new Options());

  std::auto_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( options_.get() );

  config->configFile() = "forwarder.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  FORWARDER_LOG_INIT( options_->log_cfg );
  
  return;
}

Config::~Config()
{
}

};  
