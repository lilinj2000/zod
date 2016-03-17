#include "SubServiceImpl.hh"

#include "zmq.h"
#include "Log.hh"

namespace zod
{

SubServiceImpl::SubServiceImpl(const std::string& addr, MsgCallback* callback):
    RecvService(SUB_SOCK, addr, callback)
{
  ZOD_TRACE <<"SubServiceImpl::SubServiceImpl()";
}

SubServiceImpl::~SubServiceImpl()
{
  ZOD_TRACE <<"SubServiceImpl::~SubServiceImpl()";

}

SubService* SubService::create(const std::string& addr, MsgCallback* callback)
{
  return new SubServiceImpl(addr, callback);
}

};
