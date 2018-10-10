#ifndef CSP_HANDLER_HPP
#define CSP_HANDLER_HPP

#include "BlackChannel.hpp"
#include "CabinSupervisorProt.hpp"

class CspHandler {
public:
  CspHandler();
  ~CspHandler();

  void HandleReceivedMessage(BlackChannelMessagePayload_t* aMessage);

private:
  void OnEstablishConnectionReq();         //0x01
  void OnEstablishConnectionCfm();         //0x02
  void OnEstablishConnectionRej();         //0x03

  void OnRegisterTempsensorReq();          //0x11
  void OnRegisterTempsensorCfm();          //0x12
  void OnRegisterTempsensorRej();          //0x13

  void OnTemperatureRequestFwd();          //0x14

  void OnRegisterWaterPumpReq();           //0x21
  void OnRegisterWaterPumpCfm();           //0x22
  void OnRegisterWaterPumpRej();           //0x23

  void OnRegisterWaterPumpControlInd();    //0x24
  void OnRegisterWaterPumpControlRsp();    //0x25


};


#endif //CSP_HANDLER_HPP
