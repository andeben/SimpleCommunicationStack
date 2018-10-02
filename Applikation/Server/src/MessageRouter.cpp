#include "MessageRouter.hpp"
#include "ConnectionHandler.hpp"

MessageRouter::MessageRouter()
{
  mConnection = new Server::ConnectionHandler();
}

MessageRouter::~MessageRouter()
{
  delete mConnection;
}

void MessageRouter::Run()
{

}
