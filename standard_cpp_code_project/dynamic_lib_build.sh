#!/bin/bash

# Create the build file
if [ ! -d "build" ]; then
    mkdir build
fi

# Build Cmake Project
cd build
cmake -DPLATFORM=arm -DCMAKE_BUILD_TYPE=Release ..
make -j32