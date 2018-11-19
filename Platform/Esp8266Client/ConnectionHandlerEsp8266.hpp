#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

#include <string>
#include <functional>
#include <WiFiClient.h>

#include "ConnectionHandlerIf.hpp"

const int RECEIVE_BUFFER_SIZE = 512;

class ConnectionHandler : public ConnectionHandlerIf {
public:
  ConnectionHandler(char * ip);
  ~ConnectionHandler();

  void RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback);
  void RunConnectionHandler();
  void RunReceiveHandler();
  void Send(int connectionId, char * aSendBuffer, int aDataSize);
private:
  boolean ConnectWifi();
  std::function<void(int, char*, int)> mReceiveCallback;
  WiFiClient mClient;

  boolean connectWifi();
  // Change this before you flash
  const char* mSsid = "TN_24GHz_C73195";
  const char* mPassword = "555D078790";
  boolean mWifiConnected = false;
};



#endif //CONNECTION_HANDLER_HPP
