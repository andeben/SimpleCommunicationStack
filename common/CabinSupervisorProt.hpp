#ifndef CABIN_SUPERVISOR_PROT_HPP
#define CABIN_SUPERVISOR_PROT_HPP

///////////////////////////////////////////////////////////////////////////////
///////////						Main Protocol Carrier 			    ///////////
///////////////////////////////////////////////////////////////////////////////
typedef struct {
  int      signo;
  uint8_t* payload;
} CabinSupervisorProt;


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
///////////						SIGNAL Payload structures	    ///////////
///////////////////////////////////////////////////////////////////////////////
typedef struct {
  int   supportedFunctions;
} CspEstablishConnectionReq;

typedef struct {
  int   connectionId;
} CspEstablishConnectionCfm;

typedef struct {
  int   errorCode;
} CspEstablishConnectionRej;


typedef struct {
} CspClimateRegisterTempSensorReq;

typedef struct {
  int   tempSensorId;
} CspClimateRegisterTempSensorCfm;

typedef struct {
  int   errorCode;
} CspClimateRegisterTempSensorRej;

typedef struct {
  int   temperature;
} CspClimateRegisterTemperatureFwd;

typedef struct {
} CspWaterRegisterWaterPumpReq;

typedef struct {
  int   waterPumpId;
} CspWaterRegisterWaterPumpCfm;

typedef struct {
  int   errorCode;
} CspWaterRegisterWaterPumpRej;

typedef struct {
  int   waterPumpId;
  int   cmdId;
} CspWaterRegisterWaterPumpControlInd;

typedef struct {
  int   waterPumpId;
  int   cmdId;
} CspWaterRegisterWaterPumpControlRsp;




#endif CABIN_SUPERVISO_PROT_HPP
