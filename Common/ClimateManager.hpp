#ifndef CLIMATE_MANAGER_HPP
#define CLIMATE_MANAGER_HPP

#include "TemperatureIf.hpp"

enum ClimateManagerRole {
  SERVER,
  CLIENT
};

class ClimateManager {
public:
  ClimateManager(TemperatureIf* aTemperature);
  ~ClimateManager();
  void Start(ClimateManagerRole aRole);
  int RegisterTempSensor(std::string aClientIdentifier);
  void RegisterTemperatur(int aTempSensorId, int aTemperature);

private:
  
  TemperatureIf* mTemperature;
};

#endif //CLIMATE_MANAGER_HPP
