#ifndef CSP_HANDLER_HPP
#define CSP_HANDLER_HPP

#include "BlackChannel.hpp"
#include "ConnectionManager.hpp"
#include <map>
#include <functional>
#include "CabinSupervisorProt.hpp"

class CspHandler {
public:
  CspHandler(ConnectionManager* aConnectionManager);
  ~CspHandler();

  void HandleReceivedMessage(BlackChannelMessagePayload_t* aMessage, int connectionId);

private:
  void OnEstablishConnectionReq(CabinSupervisorProt_t* aMessage, int aConnectionId);         //0x01
  void OnEstablishConnectionCfm(CabinSupervisorProt_t* aMessage, int aConnectionId);         //0x02
  void OnEstablishConnectionRej(CabinSupervisorProt_t* aMessage, int aConnectionId);         //0x03

  void OnRegisterTempsensorReq(CabinSupervisorProt_t* aMessagee, int aConnectionId);          //0x11
  void OnRegisterTempsensorCfm(CabinSupervisorProt_t* aMessagee, int aConnectionId);          //0x12
  void OnRegisterTempsensorRej(CabinSupervisorProt_t* aMessagee, int aConnectionId);          //0x13

  void OnTemperatureRequestFwd(CabinSupervisorProt_t* aMessage, int aConnectionId);          //0x14

  void OnRegisterWaterPumpReq(CabinSupervisorProt_t* aMessage, int aConnectionId);           //0x21
  void OnRegisterWaterPumpCfm(CabinSupervisorProt_t* aMessage, int aConnectionId);           //0x22
  void OnRegisterWaterPumpRej(CabinSupervisorProt_t* aMessage, int aConnectionId);           //0x23

  void OnRegisterWaterPumpControlInd(CabinSupervisorProt_t* aMessage, int aConnectionId);    //0x24
  void OnRegisterWaterPumpControlRsp(CabinSupervisorProt_t* aMessage, int aConnectionId);    //0x25

  std::map<uint8_t,std::function<void(CabinSupervisorProt_t*, int)> > mSignalHandlers;
  ConnectionManager* mConnectionManager;
};


#endif //CSP_HANDLER_HPP
