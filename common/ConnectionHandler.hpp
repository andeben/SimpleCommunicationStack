#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

#include <string>
#include <list>
#include <time.h>
#include <netinet/in.h>


namespace Server {

typedef struct Connection
{
  int connectionSocket;
  int connectionId;
};

class ConnectionHandler {
public:
  ConnectionHandler();
  ~ConnectionHandler();

  void RunConnectionHandler();
  void Receive();
  void Send(int connectionId);
private:
  int mListenSocket = 0;
  std::list<Connection> mConnection;
  int mConnectionId = 0;
  struct sockaddr_in mServAddr;
  char mSendBuff[1024];
  time_t mTicks;
};

}

namespace Client {

class ConnectionHandler {
public:
  ConnectionHandler(char * ip);
  ~ConnectionHandler();

  int Receive(char* aReceiveBuffer, int aReceiveBufferSize);

private:
  int mListenfd = 0;
  int mConnfd = 0;
  int mSocketfd = 0;
  struct sockaddr_in mClientAddr;
  time_t mTicks;

};

}

#endif //CONNECTION_HANDLER_HPP
