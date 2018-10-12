#include "ConnectionHandler.hpp"

#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>


Server::ConnectionHandler::ConnectionHandler()
{
  mListenSocket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&mServAddr, '0', sizeof(mServAddr));
  memset(mSendBuff, '0', sizeof(mSendBuff));

  mServAddr.sin_family = AF_INET;
  mServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  mServAddr.sin_port = htons(5000);

  int flags = fcntl(mListenSocket, F_GETFL);
  fcntl(mListenSocket, F_SETFL, flags | O_NONBLOCK);
  bind(mListenSocket, (struct sockaddr*)&mServAddr, sizeof(mServAddr));
  listen(mListenSocket, 10);
}

Server::ConnectionHandler::~ConnectionHandler()
{
  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    close(it->connectionSocket);
    mConnection.erase(it);
  }
}

void Server::ConnectionHandler::RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback)
{
  mReceiveCallback = aReceiveCallback;
}

void Server::ConnectionHandler::RunConnectionHandler()
{
  int result = accept(mListenSocket, (struct sockaddr*)NULL, NULL);
  if (result != -1)
  {
    Connection *newConnection = new Connection();
    newConnection->connectionId = mConnectionId++;
    newConnection->connectionSocket = result;
    int flags = fcntl(result, F_GETFL);
    fcntl(result, F_SETFL, flags | O_NONBLOCK);
    mConnection.push_back(*newConnection);

    printf("\n Found new Connection : Assign ConnectionId: %d \n", mConnectionId - 1 );
  }
}

void Server::ConnectionHandler::RunReceiveHandler()
{
  int receiveSize = 0;
  char receiveBuffer[RECEIVE_BUFFER_SIZE];
  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    receiveSize = read(it->connectionSocket, receiveBuffer, RECEIVE_BUFFER_SIZE-1);
    if (receiveSize > 0)
    {
      printf("\n Receive something \n");

      //Callback on receive
      if (mReceiveCallback != NULL)
      {
        mReceiveCallback(it->connectionId, receiveBuffer, receiveSize);
      }
    }
  }
}

void Server::ConnectionHandler::Send(int connectionId)
{
  mTicks = time(NULL);
  snprintf(mSendBuff, sizeof(mSendBuff), "%.24s\r\n", ctime(&mTicks));

  for (auto it = mConnection.begin(); it != mConnection.end(); it++)
  {
    if (it->connectionId == connectionId)
    {
      write(it->connectionSocket, mSendBuff, strlen(mSendBuff));
    }
  }
  usleep(2);
}


Client::ConnectionHandler::ConnectionHandler(char * ip)
{
  if((mSocketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Error : Could not create socket \n");
//      return 1;
      //Handle fault
  }
  memset(&mClientAddr, '0', sizeof(mClientAddr));
  mClientAddr.sin_family = AF_INET;
  mClientAddr.sin_port = htons(5000);

  if(inet_pton(AF_INET, ip, &mClientAddr.sin_addr)<=0)
  {
      printf("\n inet_pton error occured\n");
      //Todo: Handle fault
  }

  if( connect(mSocketfd, (struct sockaddr *)&mClientAddr, sizeof(mClientAddr)) < 0)
  {
     printf("\n Error : Connect Failed \n");
     //Todo: Handle fault
  }

}

Client::ConnectionHandler::~ConnectionHandler()
{

}

int Client::ConnectionHandler::Receive(char* aReceiveBuffer, int aReceiveBufferSize)
{
  int returnValue = 0;
  int receiveSize = read(mSocketfd, aReceiveBuffer, aReceiveBufferSize-1);
  if (receiveSize > 0)
  {
    returnValue = receiveSize;
  }
  return returnValue;
}


void Client::ConnectionHandler::Send(char * aSendBuffer, int aDataSize)
{
  write(mSocketfd, aSendBuffer, aDataSize);
  usleep(60);
  printf("\n Send \n");
}
