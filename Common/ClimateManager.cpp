#include "ClimateManager.hpp"


ClimateManager::ClimateManager(TemperatureIf* aTemperature) :
  mTemperature(aTemperature)
{
  
}

ClimateManager::~ClimateManager()
{
}

void ClimateManager::Start(ClimateManagerRole aRole)
{

}

int ClimateManager::RegisterTempSensor(std::string aClientIdentifier)
{
 return 0;
}

void ClimateManager::RegisterTemperatur(int aTempSensorId, int aTemperature)
{

}

