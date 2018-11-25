
#include "MessageRouter.hpp"
#include <unistd.h>
#include <functional>

#include "ConnectionIf.hpp"
#include "ConnectionLinuxServer.hpp"
#include "BlackChannel.hpp"
#include "CspHandler.hpp"
#include "Notifications.hpp"

int main(int argc, char *argv[])
{
  Connection* mConnectionHandler = new Connection();
  MessageRouter* mMessageRouter = new MessageRouter(mConnectionHandler);
  CspHandler*    mCspHandler    = new CspHandler();
  Notifications* mNotificationsHandler    = new Notifications();
  using namespace std::placeholders;
  mMessageRouter->AddSignalSubscriber(BLACK_CHANNEL_PROTOCOL_ID_CSP, std::bind(&CspHandler::HandleReceivedMessage, mCspHandler, _1));

  while(1)
  {
    mMessageRouter->Run();
    usleep(1);
  }
  delete mMessageRouter;
  delete mConnectionHandler;
}

