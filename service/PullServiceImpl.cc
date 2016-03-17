#include "PullServiceImpl.hh"

#include "zmq.h"
#include "Log.hh"

namespace zod
{

PullServiceImpl::PullServiceImpl(const std::string& addr, MsgCallback* callback):
    RecvService(PULL_SOCK, addr, callback)
{
  ZOD_TRACE <<"PullServiceImpl::PullServiceImpl()";
}

PullServiceImpl::~PullServiceImpl()
{
  ZOD_TRACE <<"PullServiceImpl::~PullServiceImpl()";
}

PullService* PullService::create(const std::string& addr, MsgCallback* callback)
{
  return new PullServiceImpl(addr, callback);
}

};
