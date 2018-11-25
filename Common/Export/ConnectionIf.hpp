#ifndef CONNECTION_IF_HPP
#define CONNECTION_IF_HPP
#include <functional>



typedef struct ConnectionStruct
{
  int connectionSocket;
  int connectionId;
} ConnectionStruct_t;

enum Result {
  CONNECTED,
  DISCONNECTED
};

class ConnectionIf {
public:
  virtual ~ConnectionIf() {};
  virtual Result Connect() = 0;
  virtual void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback) = 0;
  virtual void RunConnectionHandler() = 0;
  virtual void RunReceiveHandler() = 0;
  virtual void Send(int connectionId, char * aSendBuffer, int aDataSize) = 0;
};


#endif //CONNECTION_IF_HPP
