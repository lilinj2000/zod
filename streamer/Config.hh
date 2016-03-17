#ifndef STREAMER_CONFIG_HH
#define STREAMER_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace streamer
{

namespace po = boost::program_options;

class Options : public soil::Options
{
 public:

  Options();
  
  virtual ~Options();

  virtual po::options_description* configOptions();

  std::string pull_addr;

  std::string push_addr;
  
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class Config
{
 public:
  
  Config(int argc=0, char* argv[]=NULL);
  ~Config();

  Options* options()
  {
    return options_.get();
  }
  
 private:
  std::unique_ptr<Options> options_;

};

}  


#endif 
