##Targets##

project(node CXX C ASM)

##ESP8266-Client##
include(arduino.cmake)
add_executable(Esp8266Client ${CMAKE_SOURCE_DIR}/Application/Esp8266Client/EspMain.cpp)

target_include_directories(Esp8266Client PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(Esp8266Client PUBLIC ${CMAKE_SOURCE_DIR}/Common/Export)
target_include_directories(Esp8266Client PUBLIC ${CMAKE_SOURCE_DIR}/Platform/Esp8266Client)

target_sources(Esp8266Client PUBLIC ${Common})
target_sources(Esp8266Client PUBLIC ${ApplicationEsp8266Client})
target_sources(Esp8266Client PUBLIC ${PlatformEsp8266Client})

ARDUINO(Esp8266Client ESP8266WiFi ESP8266WebServer OneWire DallasTemperature)

