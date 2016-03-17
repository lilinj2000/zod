#include "Server.hh"
#include "Config.hh"

#include <memory>

int main(int argc, char* argv[])
{
  std::unique_ptr<bus::Config> config( new bus::Config(argc, argv) );
  
  std::unique_ptr<bus::Server> bus( new bus::Server(config->options()) );
}
