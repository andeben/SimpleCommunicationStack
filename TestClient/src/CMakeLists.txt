add_executable (Client ClientMain.cpp ${CMAKE_SOURCE_DIR}/Common/ConnectionHandler.cpp)
target_include_directories(Client PUBLIC ${CMAKE_SOURCE_DIR}/Common)

set_property(TARGET Client PROPERTY CXX_STANDARD 11)