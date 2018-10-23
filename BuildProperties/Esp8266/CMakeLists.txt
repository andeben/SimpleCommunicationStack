##Targets##

project(node CXX C ASM)

##ESP8266-Client##
include(arduino.cmake)
add_executable(Esp8266Client ${CMAKE_SOURCE_DIR}/Application/Esp8266Client/EspMain.cpp)

ARDUINO(Esp8266Client ESP8266WiFi ESP8266WebServer ESP8266mDNS)

