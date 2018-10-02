add_executable (Client ClientMain.cpp ${CMAKE_SOURCE_DIR}/common/ConnectionHandler.cpp)
target_include_directories(Client PUBLIC ${CMAKE_SOURCE_DIR}/common)

set_property(TARGET Client PROPERTY CXX_STANDARD 11)