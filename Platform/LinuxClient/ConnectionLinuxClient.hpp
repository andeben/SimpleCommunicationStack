#ifndef CONNECTION_LINUX_CLIENT_HPP
#define CONNECTION_LINUX_CLIENT_HPP

#include <string>
#include <list>
#include <time.h>
#include <netinet/in.h>
#include <functional>

#include "ConnectionIf.hpp"

const int RECEIVE_BUFFER_SIZE = 512;

class Connection : public ConnectionIf {
public:
  Connection(char * ip);
  ~Connection();

  Result Connect();
  void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback);
  void RunConnectionHandler();
  void RunReceiveHandler();
  void Send(int connectionId, char * aSendBuffer, int aDataSize);
private:

  int mConn = 0;
  int mSocket = 0;
  struct sockaddr_in mClientAddr;
  time_t mTicks = 0;
  std::function<void(int, char*, int)> mReceiveCallback;
};


#endif //CONNECTION_LINUX_CLIENT_HPP
