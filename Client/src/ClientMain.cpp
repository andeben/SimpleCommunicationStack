#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ConnectionHandler.hpp"


int main(int argc, char *argv[])
{
    int n = 0;
    char recvBuff[1024];

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    }
    Client::ConnectionHandler* mConnectionHandler = new Client::ConnectionHandler(argv[1]);

    memset(recvBuff, '0',sizeof(recvBuff));
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

    return 0;
}
