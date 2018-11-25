#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "ConnectionLinuxClient.hpp"
#include "BlackChannel.hpp"
#include "CabinSupervisorProt.hpp"


using namespace std;

Connection* mConnectionHandler;
bool isConnected = false;



void OnReceive(int aConnectionId, char* aReceiveBuffer, int aReceiveBufferSize)
{
  printf("\n *******************************OnReceive \n");
  printf("\n received message with ConnectionId id: %d \n", aConnectionId);
  for (int i = 0; i < aReceiveBufferSize; i++)
  {
    printf("%02x", aReceiveBuffer[i]);
  }
  printf("\n");
}



void send(uint8_t sigNo)
{
  BlackChannelMessagePayload_t payload;
  CabinSupervisorProt_t cabinPayload;
  memset(&payload, 0, sizeof(BlackChannelMessagePayload_t));
  memset(&cabinPayload, 0, sizeof(CabinSupervisorProt_t));
  cabinPayload.signo = sigNo;
  memcpy(payload.payload, &cabinPayload, sizeof(CabinSupervisorProt_t));
  payload.protocolId = BLACK_CHANNEL_PROTOCOL_ID_CSP;

  BlackChannelMessage_t message;
  message.signo = 0x01;
  memcpy(&message.payload, &payload, sizeof(BlackChannelMessagePayload_t));
  mConnectionHandler->Send(0, (char*)&message, sizeof(message));

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
    mConnectionHandler = new Connection(ip);
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
      send(0x01);
      send(0x02);
      send(0x03);
      send(0x11);
      send(0x12);
      send(0x13);
      send(0x14);
      send(0x21);
      send(0x22);
      send(0x23);
      send(0x24);
      send(0x25);

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
