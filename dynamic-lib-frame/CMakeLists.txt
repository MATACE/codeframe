# Set the cmake lower version.
cmake_minimum_required (VERSION 3.5)

# Describe the lib.
option(BUILD_SHARED_LIBS "Build the math shared library" ON)
set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)
# Test the cmake different name.
MESSAGE(STATUS "PROJECT NAME " ${CMAKE_PROJECT_NAME})
MESSAGE(STATUS "PROJECT NAME " ${CMAKE_})
MESSAGE(STATUS "PROJECT NAME " ${CMAKE_PROJECT_NAME})

# Set build C++ program version.
set(CMAKE_CXX_STANDARD 11)
# Set the project name.
project(codeframe)

# Judge the different platform.
if (PLATFORM MATCHES arm)
	set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    # Set the build arm platform build tool.
    set(CMAKE_CXX_COMPILER /opt/arm-2014.05/bin/arm-none-linux-gnueabi-g++)
    set(CMAKE_C_COMPILER   /opt/arm-2014.05/bin/arm-none-linux-gnueabi-gcc)
    # Set the gcc param.
    set(GNU_FLAGS "-mfpu=vfp -fPIC -lrt")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # Include the heart file.
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/include)

    # Link other libs.
    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/jsoncpp/lib)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/boost/lib)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/libs/arm/glog/lib)
# Set the pc platform.
else()
    # Set the gcc param.
    set(GNU_FLAGS "-DCOM_X64")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

    # Include the heart file.
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/boost/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/x64/ftplibpp/include)

endif()

# Add all source head file.
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
# Add all source file.
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src ALL_SRC)

add_library(codeframe ${ALL_SRC})
set_property(TARGET codeframe PROPERTY CXX_STANDARD 11)
set_property(TARGET codeframe PROPERTY CXX_STANDARD_REQUIRED ON)
if(BUILD_SHARED_LIBS)
# Set the lib version number.
set_target_properties(codeframe
    PROPERTIES
        SOVERSION ${MAJOR}
        VERSION ${MAJOR}.${MINOR}.${PATCH}
    )
endif()

# List all file.
list(APPEND TARGET_LIBRARIES codeframe)
# Set all head file.
file(GLOB ALL_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

# Create all head file.
install(FILES ${ALL_HEADERS} 
    DESTINATION "${CMAKE_CURRENT_LIST_DIR}/build/include"
)
# Create all lib file.
install(TARGETS ${TARGET_LIBRARIES}
    DESTINATION "${CMAKE_CURRENT_LIST_DIR}/build/lib/${CMAKE_BUILD_TYPE}"
)