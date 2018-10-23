#include "ConnectionHandlerEsp8266.hpp"

#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>


ConnectionHandler::ConnectionHandler()
{
}

ConnectionHandler::~ConnectionHandler()
{
}

void ConnectionHandler::RegisterOnReceiveCallback(std::function<void(int, char*, int)> aReceiveCallback)
{
}

void ConnectionHandler::RunConnectionHandler()
{
}

void ConnectionHandler::RunReceiveHandler()
{
}

void ConnectionHandler::Send(int connectionId)
{
}

