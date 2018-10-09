#ifndef MESSAGE_ROUTER_HPP
#define MESSAGE_ROUTER_HPP

#include <string>
#include <functional>

#include "ConnectionHandler.hpp"


const std::string SERVER_IP = "0.0.0.0";
const int SERVER_PORT = 5000;


class MessageRouter {
public:
  MessageRouter();
  ~MessageRouter();
  void Run();
  void AddSignalSubscriber(int aSignalNumber, std::function<void()> aCallback);
private:
  void OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize);
  Server::ConnectionHandler* mConnection;
};

#endif //MESSAGE_ROUTER_HPP
