##Targets##
project(Linux)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


##Linux-Client##
add_executable (TestClient ${CMAKE_SOURCE_DIR}/Application/LinuxClient/ClientMain.cpp)

target_include_directories(TestClient PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(TestClient PUBLIC ${CMAKE_SOURCE_DIR}/Common/Export)
target_include_directories(TestClient PUBLIC ${CMAKE_SOURCE_DIR}/Platform/LinuxClient)

target_sources(TestClient PUBLIC ${Common})
target_sources(TestClient PUBLIC ${ApplicationLinuxClient})
target_sources(TestClient PUBLIC ${PlatformLinuxClient})

set_property(TARGET TestClient PROPERTY CXX_STANDARD 11)
target_link_libraries(TestClient Threads::Threads)



##Linux-Server## 
add_executable (TestServer ${CMAKE_SOURCE_DIR}/Application/LinuxServer/ServerMain.cpp)

target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Application/LinuxServer)
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Common/Export)
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Platform/LinuxServer)


target_sources(TestServer PUBLIC ${Common})
target_sources(TestServer PUBLIC ${ApplicationLinuxServer})
target_sources(TestServer PUBLIC ${PlatformLinuxServer})

set_property(TARGET TestServer PROPERTY CXX_STANDARD 11)
target_link_libraries(TestServer Threads::Threads)


