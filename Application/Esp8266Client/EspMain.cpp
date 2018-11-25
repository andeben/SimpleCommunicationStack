#include <Arduino.h>
#include <functional>

#include "ConnectionEsp8266.hpp"
#include "Temperature.hpp"
// prototypes


Connection* mConnectionHandler;
Temperature* temp;
void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

    Serial.print("Creating ConnectionHandler");
    mConnectionHandler = new Connection("192.168.10.207");
    temp = new Temperature();
}

void loop()
{
  Serial.println("Read \n");
  temp->GetTemperature();
  Serial.println("Delay \n");
  delay(5000);


}



