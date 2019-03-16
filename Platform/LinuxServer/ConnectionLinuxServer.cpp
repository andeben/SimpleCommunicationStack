#include "ConnectionLinuxServer.hpp"

#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include "ConnectionIf.hpp"

Connection::Connection()
{
  mListenSocket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&mServAddr, '0', sizeof(mServAddr));

  mServAddr.sin_family = AF_INET;
  mServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  mServAddr.sin_port = htons(4040);

  int flags = fcntl(mListenSocket, F_GETFL);
  fcntl(mListenSocket, F_SETFL, flags | O_NONBLOCK);
  bind(mListenSocket, (struct sockaddr*)&mServAddr, sizeof(mServAddr));
  listen(mListenSocket, 10);
}

Connection::~Connection()
{
  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    close((*it)->connectionSocket);
    mConnection.erase(it);
  }
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
  std::tuple<ConnectionHandlerResult, ConnectionStruct*> returnValue =
      std::make_tuple(ConnectionHandlerResult::NO_NEW_CONNECTION, nullptr);

  int result = accept(mListenSocket, (struct sockaddr*)NULL, NULL);
  if (result != -1)
  {
    printf("\n Found new Connection \n");
    ConnectionStruct* newConnection = new ConnectionStruct();
    newConnection->connectionId = mConnectionId++;
    newConnection->connectionSocket = result;
    int flags = fcntl(result, F_GETFL);
    fcntl(result, F_SETFL, flags | O_NONBLOCK);
    mConnection.push_back(newConnection);
    returnValue = std::make_tuple(ConnectionHandlerResult::NEW_CONNECTION_ESTABLISH, newConnection);
    printf("\n Found new Connection : Assign ConnectionId: %d \n", mConnectionId - 1 );

  }

  return returnValue;
}
void Connection::RunReceiveHandler()
{
  int receiveSize = 0;
  char receiveBuffer[RECEIVE_BUFFER_SIZE];
  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    receiveSize = read((*it)->connectionSocket, receiveBuffer, RECEIVE_BUFFER_SIZE-1);
    if (receiveSize > 0)
    {
      printf("\n Receive something \n");

      //Callback on receive
      if (mReceiveCallback != NULL)
      {
        mReceiveCallback((*it)->connectionId, receiveBuffer, receiveSize);
      }
    }
  }
}

void Connection::Send(int connectionId, char * aSendBuffer, int aDataSize)
{
  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    if ((*it)->connectionId == connectionId)
    {
      write((*it)->connectionSocket, aSendBuffer, aDataSize);
    }
  }
  usleep(2);
}

