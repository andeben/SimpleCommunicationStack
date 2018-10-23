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
  virtual ~ConnectionHandlerIf() = 0;
  virtual void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback) = 0;
  virtual void RunConnectionHandler() = 0;
  virtual void RunReceiveHandler() = 0;
  virtual void Send(int connectionId) = 0;
};


#endif //CONNECTION_HANDLER_IF_HPP
