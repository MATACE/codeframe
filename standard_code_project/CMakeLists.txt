#
# For x64 compile, please use command
# cmake ..
# For arm cross compile, please use command
# cmake -DPLATFORM=arm ..
# make -j4 && make install
#

cmake_minimum_required (VERSION 3.5)

option(BUILD_SHARED_LIBS "Build the project shared library" ON)
option(SET_OUTPUT_FILE_PATH "Set the bin output file paht" OFF) 

# Set the library version.
if(BUILD_SHARED_LIBS)
    set(VERSION_MAJOR 1)
    set(VERSION_MINOR 0)
    set(VERSION_PATCH 0)

    configure_file (
        "${CMAKE_CURRENT_LIST_DIR}/version/version.h.in"
        "${CMAKE_CURRENT_LIST_DIR}/version/version.h"
        )
    include_directories(${CMAKE_CURRENT_LIST_DIR}/version)
endif(BUILD_SHARED_LIBS)

# Set the bin output file.
if(SET_OUTPUT_FILE_PATH)
    SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
        CACHE PATH
        ""
    )

    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        ""
    )

    SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
        CACHE PATH
        ""
    )
endif(SET_OUTPUT_FILE_PATH)

# Set project name.
project(pro)

# Set C and C++ build version.
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Build different platformat code.
if (PLATFORM MATCHES "arm")
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    MESSAGE(STATUS "PLATFORM NAME " ${PLATFORM})

    # Set the build cross tool.
    set(CMAKE_CXX_COMPILER /opt/arm-2014.05/bin/arm-none-linux-gnueabi-g++)
    set(CMAKE_C_COMPILER   /opt/arm-2014.05/bin/arm-none-linux-gnueabi-gcc)

    # Set the C or C++ cross tool build flag.
    set(GNU_FLAGS "-mfpu=vfp -fPIC -g -W -O2")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # Include the third use libs. 
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/include)

    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/lib)

else()
    set(GNU_FLAGS "-DCOM_X64 -g -W")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # Include the third use libs. 
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/glog/include)

    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/glog/lib)

endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src ALL_SRC)

# Set share library
if(BUILD_SHARED_LIBS)
    add_library(pro SHARED ${ALL_SRC})
else()
    add_library(pro STATIC ${ALL_SRC})
endif()

# Set C++ target
set_property(TARGET pro PROPERTY CXX_STANDARD 11)
set_property(TARGET pro PROPERTY CXX_STANDARD_REQUIRED ON)

if (PLATFORM MATCHES "arm")
    target_link_libraries(pro dl pthread rt
        ${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/lib/libglog.a)

else()
    target_link_libraries(pro dl pthread rt glog)

endif()

# Set C target
# set_property(TARGET pro PROPERTY C_STANDARD 99)
# set_property(TARGET pro PROPERTY C_STANDARD_REQUIRED ON)

if(BUILD_SHARED_LIBS)
set_target_properties(pro
    PROPERTIES
        SOVERSION ${VERSION_MAJOR}
        VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
    )
endif()



