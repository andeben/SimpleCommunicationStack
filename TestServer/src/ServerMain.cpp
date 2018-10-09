
#include "MessageRouter.hpp"
#include <unistd.h>


int main(int argc, char *argv[])
{
  MessageRouter* mMessageRouter = new MessageRouter();
  while(1)
  {
    mMessageRouter->Run();
    usleep(500);
  }
  delete mMessageRouter;
}

