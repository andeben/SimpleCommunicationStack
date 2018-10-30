#ifndef CONNECTION_HANDLER_IF_HPP
#define CONNECTION_HANDLER_IF_HPP
#include <functional>


typedef struct Connection
{
  int connectionSocket;
  int connectionId;
} Connection_t;

class ConnectionHandlerIf {
public:
  virtual ~ConnectionHandlerIf() {};
  virtual void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback) = 0;
  virtual void RunConnectionHandler() = 0;
  virtual void RunReceiveHandler() = 0;
  virtual void Send(int connectionId, char * aSendBuffer, int aDataSize) = 0;
};


#endif //CONNECTION_HANDLER_IF_HPP
