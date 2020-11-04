

cmake_minimum_required(VERSION 3.5)
include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

if(BUILD_CLIENT)
    add_executable(client_demo client_demo.c ${CLIENT_SRC})
    target_link_libraries(client_demo pthread rt zlog)

endif()

if(BUILD_SERVER)
    add_executable(server_demo server_demo.c)
    target_link_libraries(server_demo server)

endif()