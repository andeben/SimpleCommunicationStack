
#include "ConnectionHandler.hpp"
#include <unistd.h>


int main(int argc, char *argv[])
{
  Server::ConnectionHandler* mConnectionHandler = new Server::ConnectionHandler();
  while(1)
  {
    mConnectionHandler->RunConnectionHandler();
    mConnectionHandler->Send(0);
    usleep(500);
  }
  delete mConnectionHandler;
}

