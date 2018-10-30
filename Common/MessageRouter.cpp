#include "MessageRouter.hpp"
#include <functional>
#include <stdio.h>
#include <string.h>
#include "BlackChannel.hpp"


MessageRouter::MessageRouter(ConnectionHandlerIf* connectionHandler) :
  mConnection(connectionHandler)
{
  using namespace std::placeholders;
  mConnection->RegisterOnReceiveCallback(std::bind(&MessageRouter::OnReceive, this, _1, _2, _3));
}

MessageRouter::~MessageRouter()
{
}

void MessageRouter::Run()
{
//  printf("\n Run ConnectionHandler \n");

  mConnection->RunConnectionHandler();
//  printf("\n Run ReceiveHandler \n");
  mConnection->RunReceiveHandler();
}

void MessageRouter::AddSignalSubscriber(uint8_t aProtocolId, std::function<void(BlackChannelMessagePayload_t*)> aCallback)
{
  mSubscribers.insert({aProtocolId, aCallback});
}

void MessageRouter::OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize)
{
  printf("\n *******************************OnReceive \n");
  //Callback
  auto it = mSubscribers.find(((BlackChannelMessagePayload_t*)((BlackChannelMessage_t*)aReceiveBuffer)->payload)->protocolId);
  if (it != mSubscribers.end())
  {
    it->second(((BlackChannelMessagePayload_t*)((BlackChannelMessage_t*)aReceiveBuffer)->payload));
  }
}
