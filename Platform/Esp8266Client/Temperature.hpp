#ifndef TEMPERATUR_HPP
#define TEMPERATUR_HPP


#include "TemperatureIf.hpp"
#include <DallasTemperature.h>
#include <OneWire.h>

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
