#ifndef TEMPERATUR_HPP
#define TEMPERATUR_HPP


#include <DallasTemperature.h>
#include <OneWire.h>
#include "TemperatureIf.hpp"

class Temperature : public TemperatureIf {
public:
  Temperature();
  ~Temperature();

  TemperatureSensorData GetTemperature();
private:
  OneWire* mOneWire;
  DallasTemperature* mSensors;
};



#endif //CONNECTION_HANDLER_HPP
