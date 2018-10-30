#ifndef CONNECTION_HANDLER_LINUX_CLIENT_HPP
#define CONNECTION_HANDLER_LINUX_CLIENT_HPP

#include <string>
#include <list>
#include <time.h>
#include <netinet/in.h>
#include <functional>

#include "ConnectionHandlerIf.hpp"

const int RECEIVE_BUFFER_SIZE = 512;

//typedef struct Connection
//{
//  int connectionSocket;
//  int connectionId;
//} Connection_t;

class ConnectionHandler : public ConnectionHandlerIf {
public:
  ConnectionHandler();
  ~ConnectionHandler();

  void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback);
  void RunConnectionHandler();
  void RunReceiveHandler();
  void Send(int connectionId, char * aSendBuffer, int aDataSize);
private:
  int mListenSocket = 0;
  std::list<Connection> mConnection;
  int mConnectionId = 0;
  struct sockaddr_in mServAddr;
  std::function<void(int, char*, int)> mReceiveCallback;
};


#endif //CONNECTION_HANDLER_LINUX_CLIENT_HPP
