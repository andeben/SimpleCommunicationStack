
#include "MessageRouter.hpp"
#include <unistd.h>
#include <functional>

#include "BlackChannel.hpp"
#include "CspHandler.hpp"


int main(int argc, char *argv[])
{
  MessageRouter* mMessageRouter = new MessageRouter();
  CspHandler*    mCspHandler    = new CspHandler();
  while(1)
  {
    mMessageRouter->Run();
    using namespace std::placeholders;
    mMessageRouter->AddSignalSubscriber(BLACK_CHANNEL_PROTOCOL_ID_CSP, std::bind(&CspHandler::HandleReceivedMessage, mCspHandler, _1));
    usleep(500);
  }
  delete mMessageRouter;
}

