#include "Temperature.hpp"

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

Temperature::Temperature()
{
  mOneWire = new OneWire(12);
  mSensors = new DallasTemperature(mOneWire);
  mSensors->begin();
}

Temperature::~Temperature()
{
}

TemperatureSensorData Temperature::GetTemperature()
{
  Serial.print(" Requesting temperatures...");
  mSensors->requestTemperatures(); // Send the command to get temperature readings
  Serial.println("DONE");
 /********************************************************************/
  Serial.print("Temperature is: ");
  Serial.print(mSensors->getTempCByIndex(0)); // Why "byIndex"?

  TemperatureSensorData retVal;
  return retVal;
}

