#ifndef BUS_SERVER_HH
#define BUS_SERVER_HH

namespace bus
{

class Options;

class Server
{
 public:
  Server(Options* options);

  virtual ~Server();

 private:

  Options* options_;
  
  void* context_;
  void* router_;
  void* dealer_;
  
};


};

#endif
