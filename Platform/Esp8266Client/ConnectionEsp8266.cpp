#include "ConnectionEsp8266.hpp"

#include <WiFiClient.h>
#include <ESP8266WiFi.h>


Connection::Connection(char * ip)
{
  // Initialise wifi connection
  mWifiConnected = ConnectWifi();
//  if (mWifiConnected)
//  {
//    IPAddress address;
//    address.fromString(ip);
//    mClient.connect(address, 4040);
//  }
}

Connection::~Connection()
{
}

ConnectResult Connection::SetupConnection()
{
 return ConnectResult::CONNECTED;
}

void Connection::RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback)
{
  mReceiveCallback = aReceiveCallback;
}

std::tuple<ConnectionHandlerResult, ConnectionStruct*> Connection::RunConnectionHandler()
{
  return std::make_tuple(ConnectionHandlerResult::NO_NEW_CONNECTION, nullptr);
}

void Connection::RunReceiveHandler()
{
}

void Connection::Send(int connectionId, char * aSendBuffer, int aDataSize)
{
}

boolean Connection::ConnectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(mSsid, mPassword);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 10){
      state = false;
      break;
    }
    i++;
  }

  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(mSsid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }

  return state;
}
