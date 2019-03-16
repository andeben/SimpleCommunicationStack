#ifndef MESSAGE_ROUTER_HPP
#define MESSAGE_ROUTER_HPP

#include <string>
#include <functional>
#include <map>

#include "ConnectionIf.hpp"
#include "BlackChannel.hpp"
#include "CabinSupervisorProt.hpp"

class MessageRouter {
public:
  MessageRouter(ConnectionIf* connectionHandler);
  ~MessageRouter();
  void Run();
  void AddSignalSubscriber(uint8_t aProtocolId, std::function<void(BlackChannelMessagePayload_t*, int)>  aCallback);
private:
  void OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize);
  ConnectionIf* mConnection;
  std::map<uint8_t,std::function<void(BlackChannelMessagePayload_t*, int)> > mSubscribers;

};

#endif //MESSAGE_ROUTER_HPP
