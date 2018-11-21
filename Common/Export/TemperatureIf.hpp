#ifndef TEMPERATURE_IF_HPP
#define TEMPERATURE_IF_HPP
#include <functional>


typedef struct TemperatureSensorData
{
  int tempSensorId;
  int temperature_c;
} TemperatureSensorData_t;

class TemperatureIf {
public:
  virtual ~TemperatureIf() {};
  virtual TemperatureSensorData GetTemperature() = 0;
};


#endif //TEMPERATURE_IF_HPP
