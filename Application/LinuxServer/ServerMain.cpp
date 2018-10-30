
#include "MessageRouter.hpp"
#include <unistd.h>
#include <functional>

#include "BlackChannel.hpp"
#include "CspHandler.hpp"
#include "ConnectionHandlerIf.hpp"
#include "ConnectionHandlerLinuxServer.hpp"

int main(int argc, char *argv[])
{
  ConnectionHandler* mConnectionHandler = new ConnectionHandler();
  MessageRouter* mMessageRouter = new MessageRouter(mConnectionHandler);
  CspHandler*    mCspHandler    = new CspHandler();
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

