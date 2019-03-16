
#include <unistd.h>
#include <functional>

#include "ConnectionLinuxServer.hpp"
#include "ConnectionManager.hpp"
#include "BlackChannel.hpp"
#include "CspHandler.hpp"
#include "Notifications.hpp"

int main(int argc, char *argv[])
{
  Connection* mConnectionHandler = new Connection();
  ConnectionManager* mConnectionManager = new ConnectionManager(mConnectionHandler);
  CspHandler*    mCspHandler    = new CspHandler(mConnectionManager);
  Notifications* mNotificationsHandler    = new Notifications();
  using namespace std::placeholders;
  mConnectionManager->GetMessageRouter()->AddSignalSubscriber(BLACK_CHANNEL_PROTOCOL_ID_CSP, std::bind(&CspHandler::HandleReceivedMessage, mCspHandler, _1, _2));

  while(1)
  {
    mConnectionManager->Run();
    usleep(1);
  }
  delete mConnectionManager;
  delete mConnectionHandler;

}

