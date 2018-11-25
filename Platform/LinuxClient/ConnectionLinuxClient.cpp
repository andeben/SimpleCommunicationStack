#include "ConnectionLinuxClient.hpp"

#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>



Connection::Connection(char * ip)
{
  if((mSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Error : Could not create socket \n");
    //      return 1;
    //Handle fault
  }
  memset(&mClientAddr, '0', sizeof(mClientAddr));
  mClientAddr.sin_family = AF_INET;
  mClientAddr.sin_port = htons(4050);

  if(inet_pton(AF_INET, ip, &mClientAddr.sin_addr)<=0)
  {
    printf("\n inet_pton error occured\n");
    //Todo: Handle fault
  }

  if( connect(mSocket, (struct sockaddr *)&mClientAddr, sizeof(mClientAddr)) < 0)
  {
    printf("\n Error : Connect Failed \n");
    //Todo: Handle fault
  }
}

Connection::~Connection()
{
}

Result Connection::Connect()
{
  return Result::CONNECTED;
}

void Connection::RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback)
{
  mReceiveCallback = aReceiveCallback;
}

void Connection::RunConnectionHandler()
{
  //Only accept one connection, do nothing here
}

void Connection::RunReceiveHandler()
{
  int receiveSize = 0;
  char receiveBuffer[RECEIVE_BUFFER_SIZE];
  receiveSize = read(mSocket, receiveBuffer, RECEIVE_BUFFER_SIZE-1);
  if (receiveSize > 0)
  {
    printf("\n Receive something \n");

    //Callback on receive
    if (mReceiveCallback != NULL)
    {
      mReceiveCallback(0, receiveBuffer, receiveSize);
    }
  }
}

void Connection::Send(int connectionId, char * aSendBuffer, int aDataSize)
{
  write(mSocket, aSendBuffer, aDataSize);
  usleep(60);
  printf("\n Send \n");
}

