#include "CspHandler.hpp"


CspHandler::CspHandler()
{
}

CspHandler::~CspHandler()
{
}

void CspHandler::HandleReceivedMessage(CabinSupervisorProt aMessage)
{

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
