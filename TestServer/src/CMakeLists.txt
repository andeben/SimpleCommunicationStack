 
add_executable (TestServer ServerMain.cpp)

aux_source_directory(${CMAKE_SOURCE_DIR}/Common Common)
aux_source_directory(${CMAKE_SOURCE_DIR}/Application/Server Application)


target_sources(TestServer PUBLIC ${Common})
target_sources(TestServer PUBLIC ${Application})
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(TestServer PUBLIC ${CMAKE_SOURCE_DIR}/Application/Server)
set_property(TARGET TestServer PROPERTY CXX_STANDARD 11)