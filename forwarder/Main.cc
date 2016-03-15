#include "Server.hh"
#include "Config.hh"

#include <memory>

int main(int argc, char* argv[])
{
  std::unique_ptr<forwarder::Config> config( new forwarder::Config(argc, argv) );
  
  std::unique_ptr<forwarder::Server> forwarder( new forwarder::Server(config->options()) );
}
