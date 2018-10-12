#ifndef CABIN_SUPERVISOR_PROT_HPP
#define CABIN_SUPERVISOR_PROT_HPP

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
///////////						Main Protocol Carrier 			    ///////////
///////////////////////////////////////////////////////////////////////////////
typedef struct {
  uint8_t signo;
  uint8_t payload[100];
} CabinSupervisorProt_t;



///////////////////////////////////////////////////////////////////////////////
///////////						SIGNAL DEFINITION     			    ///////////
///////////////////////////////////////////////////////////////////////////////
#define CSP_ESTABLISH_CONNECTION_REQ			         0x01
#define CSP_ESTABLISH_CONNECTION_CFM 			         0x02
#define CSP_ESTABLISH_CONNECTION_REJ			         0x03

#define CSP_CLIMATE_REGISTER_TEMPSENSOR_REQ        0x11
#define CSP_CLIMATE_REGISTER_TEMPSENSOR_CFM	       0x12
#define CSP_CLIMATE_REGISTER_TEMPSENSOR_REJ	       0x13

#define CSP_CLIMATE_REGISTER_TEMPERATURE_FWD       0x14

#define CSP_WATER_REGISTER_WATERPUMP_REQ           0x21
#define CSP_WATER_REGISTER_WATERPUMP_CFM	         0x22
#define CSP_WATER_REGISTER_WATERPUMP_REJ	         0x23

#define CSP_WATER_REGISTER_WATERPUMPCONTROL_IND    0x24
#define CSP_WATER_REGISTER_WATERPUMPCONTROL_RSP    0x25


///////////////////////////////////////////////////////////////////////////////
///////////						SIGNAL Payload structures	                    ///////////
///////////////////////////////////////////////////////////////////////////////
typedef struct {
  uint8_t   supportedFunctions;
} CspEstablishConnectionReq;

typedef struct {
  uint8_t   connectionId;
} CspEstablishConnectionCfm;

typedef struct {
  uint8_t   errorCode;
} CspEstablishConnectionRej;


typedef struct {
} CspClimateRegisterTempSensorReq;

typedef struct {
  uint8_t   tempSensorId;
} CspClimateRegisterTempSensorCfm;

typedef struct {
  uint8_t   errorCode;
} CspClimateRegisterTempSensorRej;

typedef struct {
  uint8_t   temperature;
} CspClimateRegisterTemperatureFwd;

typedef struct {
} CspWaterRegisterWaterPumpReq;

typedef struct {
  uint8_t   waterPumpId;
} CspWaterRegisterWaterPumpCfm;

typedef struct {
  uint8_t   errorCode;
} CspWaterRegisterWaterPumpRej;

typedef struct {
  uint8_t   waterPumpId;
  uint8_t   cmdId;
} CspWaterRegisterWaterPumpControlInd;

typedef struct {
  uint8_t   waterPumpId;
  uint8_t   cmdId;
} CspWaterRegisterWaterPumpControlRsp;



#endif //CABIN_SUPERVISOR_PROT_HPP
