#!/bin/bash

# if [ ! -d "build" ]; then
    # mkdir build
# fi

# cd build

if [  "$1"x = "r"x ]
then
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    # cmake -DCMAKE_BUILD_TYPE=Release ..
elif [  "$1"x = "c"x ]
then
    echo "NO"
fi

make -j32
