 
add_executable (Server ServerMain.cpp)

aux_source_directory(${CMAKE_SOURCE_DIR}/common Common)
aux_source_directory(${CMAKE_SOURCE_DIR}/Application/Server/src Application)


target_sources(Server PUBLIC ${Common})
target_sources(Server PUBLIC ${Application})
target_include_directories(Server PUBLIC ${CMAKE_SOURCE_DIR}/common)
set_property(TARGET Server PROPERTY CXX_STANDARD 11)