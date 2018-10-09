#include "MessageRouter.hpp"
#include <functional>
#include "ConnectionHandler.hpp"


MessageRouter::MessageRouter()
{
  mConnection = new Server::ConnectionHandler();
  using namespace std::placeholders;
  mConnection->RegisterOnReceiveCallback(std::bind(&MessageRouter::OnReceive, this, _1, _2, _3));
}

MessageRouter::~MessageRouter()
{
  delete mConnection;
}

void MessageRouter::Run()
{
  mConnection->RunConnectionHandler();
  mConnection->RunReceiveHandler();
}

void MessageRouter::AddSignalSubscriber(int aSignalNumber, std::function<void()> aCallback)
{

}

void MessageRouter::OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize)
{
  printf("\n ------------------MessageRouter::OnReceive---------------------: ");
  printf("\n Received Message(%d) from Connection %d: ", aReceiveBufferSize, aConnectionId);
  for (int i = 0; i < aReceiveBufferSize; i++)
  {
    printf("%02X", aReceiveBuffer[i]);
  }
  printf("\n");
}
