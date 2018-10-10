#include "CspHandler.hpp"
#include <stdio.h>

CspHandler::CspHandler()
{
}

CspHandler::~CspHandler()
{
}

void CspHandler::HandleReceivedMessage(BlackChannelMessagePayload_t* aMessage)
{
  printf("\n ------------------CspHandler::HandleReceivedMessage---------------------: ");
  printf("\n received message with protocol id: %d \n", aMessage->protocolId);
  for (int i = 0; i < sizeof(aMessage->payload); i++)
  {
    printf("%02x", aMessage->payload[i]);
  }
  printf("\n");
}


void CspHandler::OnEstablishConnectionReq(){}
void CspHandler::OnEstablishConnectionCfm(){}
void CspHandler::OnEstablishConnectionRej(){}

void CspHandler::OnRegisterTempsensorReq(){}
void CspHandler::OnRegisterTempsensorCfm(){}
void CspHandler::OnRegisterTempsensorRej(){}

void CspHandler::OnTemperatureRequestFwd(){}

void CspHandler::OnRegisterWaterPumpReq(){}
void CspHandler::OnRegisterWaterPumpCfm(){}
void CspHandler::OnRegisterWaterPumpRej(){}

void CspHandler::OnRegisterWaterPumpControlInd(){}
void CspHandler::OnRegisterWaterPumpControlRsp(){}
