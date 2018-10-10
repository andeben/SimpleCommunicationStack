#include "MessageRouter.hpp"
#include <functional>
#include <stdio.h>
#include <string.h>
#include "BlackChannel.hpp"
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

void MessageRouter::AddSignalSubscriber(uint8_t aProtocolId, std::function<void(BlackChannelMessagePayload_t*)> aCallback)
{
  mSubscribers.insert({aProtocolId, aCallback});
}

void MessageRouter::OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize)
{
//  printf("\n ------------------MessageRouter::OnReceive---------------------: ");
//  printf("\n Received Message(%d) from Connection %d: ", aReceiveBufferSize, aConnectionId);
//  for (int i = 0; i < aReceiveBufferSize; i++)
//  {
//    printf("%02X", aReceiveBuffer[i]);
//  }
//  printf("\n");
  //Callback
  auto it = mSubscribers.find(((BlackChannelMessagePayload_t*)((BlackChannelMessage_t*)aReceiveBuffer)->payload)->protocolId);
  if (it != mSubscribers.end())
  {
    it->second(((BlackChannelMessagePayload_t*)((BlackChannelMessage_t*)aReceiveBuffer)->payload));
  }
}
