cmake_minimum_required (VERSION 3.6)


aux_source_directory(${CMAKE_SOURCE_DIR}/Common Common)

aux_source_directory(${CMAKE_SOURCE_DIR}/Application/LinuxClient ApplicationLinuxClient)
aux_source_directory(${CMAKE_SOURCE_DIR}/Application/LinuxServer ApplicationLinuxServer)

aux_source_directory(${CMAKE_SOURCE_DIR}/Platform/LinuxClient PlatformLinuxClient)
aux_source_directory(${CMAKE_SOURCE_DIR}/Platform/LinuxServer PlatformLinuxServer)



#add_library(CommonLib OBJECT ${Common})
#set_property(TARGET CommonLib PROPERTY CXX_STANDARD 11)

add_subdirectory (BuildProperties/Linux)
add_subdirectory (BuildProperties/Esp8266)
