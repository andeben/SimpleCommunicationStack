#ifndef MESSAGE_ROUTER_HPP
#define MESSAGE_ROUTER_HPP

#include <string>
#include "ConnectionHandler.hpp"


const std::string SERVER_IP = "0.0.0.0";
const int SERVER_PORT = 5000;


class MessageRouter {
public:
  MessageRouter();
  ~MessageRouter();
  void Run();
private:
  Server::ConnectionHandler* mConnection;
};

#endif MESSAGE_ROUTER_HPP
