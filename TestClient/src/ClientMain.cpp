#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "ConnectionHandler.hpp"


using namespace std;

Client::ConnectionHandler* mConnectionHandler;
bool isConnected = false;

void receive(){
  char recvBuff[1024];
  memset(recvBuff, '0',sizeof(recvBuff));
  int n = 0;
  while ( (n = mConnectionHandler->Receive(recvBuff, sizeof(recvBuff)-1)) > 0)
  {
    recvBuff[n] = 0;
    if(fputs(recvBuff, stdout) == EOF)
    {
      printf("\n Error : Fputs error\n");
    }
  }
  if(n < 0)
  {
    printf("\n Read error \n");
  }
}

void send()
{
  char sendBuffer[40] = "Hello WOrld";
  mConnectionHandler->Send(sendBuffer, 40);

}

bool connect(char * ip)
{
  printf("\n Connecting to Ip: %s <ip of server> \n",ip);
  if (isConnected == true)
  {
    printf("\n Failed to connect, already connected \n");
    return false;
  }
  else
  {
    mConnectionHandler = new Client::ConnectionHandler(ip);
    isConnected = true;
    return true;
  }
}

int main(int argc, char *argv[])
{
  int myNumber = 0;
  if(argc != 2)
  {
    printf("\n Usage: %s <ip of server> \n",argv[0]);
    return 1;
  }
  string input = "";
  while (true) {
    myNumber = 0;
    cout << ":------------MENU------------:  \n";
    cout << ":-----------Connect----------: 1\n";
    cout << ":--------Send Request--------: 2\n";
    cout << ":----------------------------: 3\n";
    cout << ":----------------------------: 4\n";
    cout << ":----------------------------: 5\n";
    cout << ":----------------------------: 6\n";
    cout << ":----------------------------: 7\n";
    cout << ":----------------------------: 8\n";
    cout << ":-------------EXIT-----------: 9\n";
    cout << "Please enter a valid menu option: \n";
    getline(cin, input);

    // This code converts from string to number safely.
    stringstream myStream(input);
    myStream >> myNumber;

    if (myNumber == 1)
    {
      connect(argv[1]);
    }
    else if (myNumber == 2)
    {
      //Send Request
      cout << "Send Request" << endl;
      send();
    }
    else if (myNumber == 9)
    {
      cout << "Exit" << endl;
      //exit
      break;
    }
    else
    {
      cout << "Invalid number, please try again" << endl;
    }
  }
 cout << "Exit Called" << endl;

 return 0;
}
