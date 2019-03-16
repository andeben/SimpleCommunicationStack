#ifndef CONNECTION_IF_HPP
#define CONNECTION_IF_HPP
#include <functional>
#include <tuple>


typedef struct ConnectionStruct
{
  int connectionSocket;
  int connectionId;
} ConnectionStruct_t;

enum ConnectResult {
  CONNECTED,
  DISCONNECTED
};

enum ConnectionHandlerResult {
  NO_NEW_CONNECTION,
  NEW_CONNECTION_ESTABLISH,
  ERROR
};


class ConnectionIf {
public:
  virtual ~ConnectionIf() {};
  virtual ConnectResult SetupConnection() = 0;
  virtual void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback) = 0;
  virtual std::tuple<ConnectionHandlerResult, ConnectionStruct*> RunConnectionHandler() = 0;
  virtual void RunReceiveHandler() = 0;
  virtual void Send(int aConnectionId, char * aSendBuffer, int aDataSize) = 0;
};


#endif //CONNECTION_IF_HPP
