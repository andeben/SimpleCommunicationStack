#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <string>
#include <list>
#include "ConnectionIf.hpp"
#include "MessageRouter.hpp"

class ConnectionManager {
public:
  ConnectionManager(ConnectionIf* aConnection);
  ~ConnectionManager();
  void Run();
  MessageRouter* GetMessageRouter();
  int RegisterEstablishedConnection(int aConnectionId, std::string aClientIdentifier);
  void Send(int aConnectionId, char * aSendBuffer, int aDataSize);
private:
  typedef struct Client_t
  {
    int          clientId;
    std::string  clientIdentifier;
    int          connectionId;
  } Client_t;
  ConnectionIf* mConnection;
  MessageRouter* mMessageRouter;
  ConnectResult mConnnecStatus;
  std::list<Client_t*> mClients;
  int nextFreeClientId = 0;

};

#endif //CONNECTION_MANAGER_HPP
