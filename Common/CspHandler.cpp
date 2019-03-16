#include "CspHandler.hpp"
#include <stdio.h>

CspHandler::CspHandler(ConnectionManager* aConnectionManager) :
     mConnectionManager(aConnectionManager)
{
  using namespace std::placeholders;
  mSignalHandlers.insert({0x01, std::bind(&CspHandler::OnEstablishConnectionReq, this, _1, _2)});
  mSignalHandlers.insert({0x02, std::bind(&CspHandler::OnEstablishConnectionCfm, this, _1, _2)});
  mSignalHandlers.insert({0x03, std::bind(&CspHandler::OnEstablishConnectionRej, this, _1, _2)});
  mSignalHandlers.insert({0x11, std::bind(&CspHandler::OnRegisterTempsensorReq,  this, _1, _2)});
  mSignalHandlers.insert({0x12, std::bind(&CspHandler::OnRegisterTempsensorCfm,  this, _1, _2)});
  mSignalHandlers.insert({0x13, std::bind(&CspHandler::OnRegisterTempsensorRej,  this, _1, _2)});

  mSignalHandlers.insert({0x14, std::bind(&CspHandler::OnTemperatureRequestFwd,  this, _1, _2)});

  mSignalHandlers.insert({0x21, std::bind(&CspHandler::OnRegisterWaterPumpReq,  this, _1, _2)});
  mSignalHandlers.insert({0x22, std::bind(&CspHandler::OnRegisterWaterPumpCfm,  this, _1, _2)});
  mSignalHandlers.insert({0x23, std::bind(&CspHandler::OnRegisterWaterPumpRej,  this, _1, _2)});

  mSignalHandlers.insert({0x24, std::bind(&CspHandler::OnRegisterWaterPumpControlInd,  this, _1, _2)});
  mSignalHandlers.insert({0x25, std::bind(&CspHandler::OnRegisterWaterPumpControlRsp,  this, _1, _2)});
}

CspHandler::~CspHandler()
{
}

void CspHandler::HandleReceivedMessage(BlackChannelMessagePayload_t* aMessage, int connectionId)
{
  auto it = mSignalHandlers.find(((CabinSupervisorProt_t*)aMessage->payload)->signo);
  if (it != mSignalHandlers.end())
  {
    it->second((CabinSupervisorProt_t*)aMessage, connectionId);
  }
}


void CspHandler::OnEstablishConnectionReq(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  int clientId = mConnectionManager->RegisterEstablishedConnection(aConnectionId, std::string(((CspEstablishConnectionReq*)aMessage->payload)->clientIdentifier));
  CspEstablishConnectionCfm returnPayload;
  returnPayload.clientId = clientId;
  mConnectionManager->Send(aConnectionId, (char *)&returnPayload, sizeof(returnPayload));
  printf("\n ------------------CspHandler::OnEstablishConnectionReq---------------------: \n");

}

void CspHandler::OnEstablishConnectionCfm(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnEstablishConnectionCfm---------------------: \n");

}

void CspHandler::OnEstablishConnectionRej(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnEstablishConnectionRej---------------------: \n");
}

void CspHandler::OnRegisterTempsensorReq(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterTempsensorReq---------------------: \n");
}

void CspHandler::OnRegisterTempsensorCfm(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterTempsensorCfm---------------------: \n");
}

void CspHandler::OnRegisterTempsensorRej(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterTempsensorRej---------------------: \n");
}
void CspHandler::OnTemperatureRequestFwd(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnTemperatureRequestFwd---------------------: \n");
}

void CspHandler::OnRegisterWaterPumpReq(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterWaterPumpReq---------------------: \n");
}
void CspHandler::OnRegisterWaterPumpCfm(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterWaterPumpCfm---------------------: \n");
}
void CspHandler::OnRegisterWaterPumpRej(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterWaterPumpRej---------------------: \n");
}

void CspHandler::OnRegisterWaterPumpControlInd(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterWaterPumpControlInd---------------------: \n");
}
void CspHandler::OnRegisterWaterPumpControlRsp(CabinSupervisorProt_t* aMessage, int aConnectionId)
{
  printf("\n ------------------CspHandler::OnRegisterWaterPumpControlRsp---------------------: \n");
}
