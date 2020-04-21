#
# mkdir build
# cd build
# For x64 compile, please use command
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# For arm cross compile, please use command
# cmake -DPLATFORM=arm -DCMAKE_BUILD_TYPE=Release ..
# make -j4
#
cmake_minimum_required(VERSION 3.5)   # CMake version check
include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

if(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "None")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Debug")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "CMAKE_BUILD_TYPE is Release")
else()
    MESSAGE(STATUS "unknown CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
endif()

if(PLATFORM MATCHES "arm")
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    set(CMAKE_CXX_COMPILER /opt/arm-2014.05/bin/arm-none-linux-gnueabi-g++)
    set(CMAKE_C_COMPILER   /opt/arm-2014.05/bin/arm-none-linux-gnueabi-gcc)

    set(GNU_FLAGS "-mfpu=vfp -fPIC -g -W -DBOOST_ASIO_DISABLE_STD_FUTURE")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/include)

    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/lib)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/lib)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/lib)
else()
    set(GNU_FLAGS "-DCOM_X64 -g -W")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/x64/boost/include)

    link_directories(${CMAKE_CURRENT_LIST_DIR}/lib/x64/boost/lib)
endif()

#include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/jsoncpp/include/)
#link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/jsoncpp/lib)

add_executable(demo demo.cpp)
set_property(TARGET demo PROPERTY CXX_STANDARD 11)
set_property(TARGET demo PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(demo glog dl)