#include "Server.hh"
#include "Config.hh"

#include <memory>

int main(int argc, char* argv[])
{
  std::unique_ptr<streamer::Config> config( new streamer::Config(argc, argv) );
  
  std::unique_ptr<streamer::Server> streamer( new streamer::Server(config->options()) );
}
