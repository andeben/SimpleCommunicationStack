#ifndef CONNECTION_LINUX_CLIENT_HPP
#define CONNECTION_LINUX_CLIENT_HPP

#include <string>
#include <list>
#include <time.h>
#include <netinet/in.h>
#include <functional>
#include <tuple>

#include "ConnectionIf.hpp"

const int RECEIVE_BUFFER_SIZE = 512;

class Connection : public ConnectionIf {
public:
  Connection();
  ~Connection();
  ConnectResult SetupConnection();
  void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback);
  std::tuple<ConnectionHandlerResult, ConnectionStruct*> RunConnectionHandler();
  void RunReceiveHandler();
  void Send(int connectionId, char * aSendBuffer, int aDataSize);

private:
  int mListenSocket = 0;
  std::list<ConnectionStruct*> mConnection;
  int mConnectionId = 0;
  struct sockaddr_in mServAddr;
  std::function<void(int, char*, int)> mReceiveCallback;
};


#endif //CONNECTION_LINUX_CLIENT_HPP
