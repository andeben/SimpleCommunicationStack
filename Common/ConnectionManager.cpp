#include "ConnectionManager.hpp"


ConnectionManager::ConnectionManager(ConnectionIf* aConnection) :
  mConnection(aConnection)
{
  mMessageRouter = new MessageRouter(mConnection);
  mConnnecStatus = mConnection->SetupConnection();
}

ConnectionManager::~ConnectionManager()
{
  delete mMessageRouter;
}

void ConnectionManager::Run()
{
  std::tuple<ConnectionHandlerResult, ConnectionStruct*> connection = mConnection->RunConnectionHandler();
  if (std::get<0>(connection) == ConnectionHandlerResult::NEW_CONNECTION_ESTABLISH)
  {
    mClients.push_back(new Client_t[nextFreeClientId++, "null", std::get<1>(connection)->connectionId]);
  }
  mMessageRouter->Run();
}

MessageRouter* ConnectionManager::GetMessageRouter()
{
  return mMessageRouter;
}

void ConnectionManager::Send(int aConnectionId, char * aSendBuffer, int aDataSize)
{
  mConnection->Send(aConnectionId, aSendBuffer, aDataSize);
}

int ConnectionManager::RegisterEstablishedConnection(int aConnectionId, std::string aClientIdentifier)
{
  //Uppdatera ClientIdentifier för anslutningen
  //Ta bort andra instanser av samma clientid
  //returnera 
  return 0;

}