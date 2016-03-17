#ifndef BUS_CONFIG_HH
#define BUS_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace bus
{

namespace po = boost::program_options;

class Options : public soil::Options
{
 public:

  Options();
  
  virtual ~Options();

  virtual po::options_description* configOptions();

  std::string router_addr;

  std::string dealer_addr;
  
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
