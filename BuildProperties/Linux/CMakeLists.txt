##Targets##
project(Linux)
##Linux-Client##
add_executable (TestClient ${CMAKE_SOURCE_DIR}/Application/LinuxClient/ClientMain.cpp)
target_sources(TestClient PUBLIC ${Common})
target_sources(TestClient PUBLIC ${ApplicationLinuxClient})
target_include_directories(TestClient PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(TestClient PUBLIC ${CMAKE_SOURCE_DIR}/Application/LinuxClient)
set_property(TARGET TestClient PROPERTY CXX_STANDARD 11)

##Linux-Server## 
add_executable (TestServer ${CMAKE_SOURCE_DIR}/Application/LinuxServer/ServerMain.cpp)
target_sources(TestServer PUBLIC ${Common})
target_sources(TestServer PUBLIC ${ApplicationLinuxServer})
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Application/LinuxServer)
set_property(TARGET TestServer PROPERTY CXX_STANDARD 11)


