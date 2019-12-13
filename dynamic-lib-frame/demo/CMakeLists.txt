# CMake version check
cmake_minimum_required(VERSION 3.5)   
# Set the cmake file.
include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)
# Set the build param.
set(GNU_FLAGS "-DCOM_X64")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS}")
    set(CMAKE_C_FLAGS   "${GNU_FLAGS}")

# Run the demo.
add_executable(demo demo.c)
set_property(TARGET demo PROPERTY CXX_STANDARD 11)
set_property(TARGET demo PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(demo dl)