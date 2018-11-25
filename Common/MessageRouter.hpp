#ifndef MESSAGE_ROUTER_HPP
#define MESSAGE_ROUTER_HPP

#include <string>
#include <functional>
#include <map>

#include "ConnectionIf.hpp"
#include "BlackChannel.hpp"
#include "CabinSupervisorProt.hpp"

const std::string SERVER_IP = "0.0.0.0";
const int SERVER_PORT = 5000;

class MessageRouter {
public:
  MessageRouter(ConnectionIf* connectionHandler);
  ~MessageRouter();
  void Run();
  void AddSignalSubscriber(uint8_t aProtocolId, std::function<void(BlackChannelMessagePayload_t*)>  aCallback);
private:
  void OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize);
  ConnectionIf* mConnection;
  std::map<uint8_t,std::function<void(BlackChannelMessagePayload_t*)> > mSubscribers;

};

#endif //MESSAGE_ROUTER_HPP
