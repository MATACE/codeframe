#
# For x64 compile, please use command
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# For arm cross compile, please use command
# cmake -DPLATFORM=arm -DCMAKE_BUILD_TYPE=Release ..
# make -j4 && make install
#
cmake_minimum_required (VERSION 3.5)

option(BUILD_SHARED_LIBS "Build the math shared library" ON)
set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)

set(CMAKE_BUILD_TYPE Debug)
project(pro)
set(CMAKE_CXX_STANDARD 11)

MESSAGE(STATUS "PROJECT NAME " ${CMAKE_PROJECT_NAME})
MESSAGE(STATUS "PROJECT NAME " ${CMAKE_})
MESSAGE(STATUS "PROJECT NAME " ${CMAKE_PROJECT_NAME})

if(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "None")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Debug")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "CMAKE_BUILD_TYPE is Release")
else()
    MESSAGE(STATUS "unknown CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
endif()

if (PLATFORM MATCHES "arm")
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    MESSAGE(STATUS "PLATFORM NAME " ${PLATFORM})

    set(CMAKE_CXX_COMPILER /opt/arm-2014.05/bin/arm-none-linux-gnueabi-g++)
    set(CMAKE_C_COMPILER   /opt/arm-2014.05/bin/arm-none-linux-gnueabi-gcc)

    MESSAGE(STATUS "CMAKE_CXX_COMPILER NAME " ${CMAKE_CXX_COMPILER})
    MESSAGE(STATUS "CMAKE_C_COMPILER NAME " ${CMAKE_C_COMPILER})

    set(GNU_FLAGS "-mfpu=vfp -fPIC -g -W -O2 -DBOOST_ASIO_DISABLE_STD_FUTURE")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/include)
    # include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/include)
    # include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/include)

    # link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/lib)
    # link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/lib)
    # link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/lib)

else()
    set(GNU_FLAGS "-DCOM_X64 -g -W")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/jsoncpp/include/)

    # link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/jsoncpp/lib)

endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src ALL_SRC)

# add_executable(pro_demo ${ALL_SRC})

add_library(pro SHARED ${ALL_SRC})
set_property(TARGET pro PROPERTY CXX_STANDARD 11)
set_property(TARGET pro PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(pro glog dl)

if(BUILD_SHARED_LIBS)
set_target_properties(pro
    PROPERTIES
        SOVERSION ${MAJOR}
        VERSION ${MAJOR}.${MINOR}.${PATCH}
    )
endif()

# list(APPEND TARGET_LIBRARIES pro)

# file(GLOB ALL_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

# install(FILES ${ALL_HEADERS} 
#     DESTINATION "${CMAKE_CURRENT_LIST_DIR}/build/include"
# )

# install(TARGETS ${TARGET`_LIBRARIES}
#     DESTINATION "${CMAKE_CURRENT_LIST_DIR}/build/lib/${CMAKE_BUILD_TYPE}"
# )