
#include "MessageRouter.hpp"
#include <unistd.h>
#include <functional>

#include "CspHandler.hpp"

int main(int argc, char *argv[])
{
  MessageRouter* mMessageRouter = new MessageRouter();
  CspHandler*    mCspHandler    = new CspHandler();
  while(1)
  {
    mMessageRouter->Run();
    using namespace std::placeholders;
    mMessageRouter->AddSignalSubscriber(CSP_ESTABLISH_CONNECTION_REQ, std::bind(&CspHandler::HandleReceivedMessage, mCspHandler, _1));
    usleep(500);
  }
  delete mMessageRouter;
}

