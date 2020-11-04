#!/bin/bash

LIB_NAME="pro"

MAJOR_NAME="VERSION_MAJOR"
MINOR_NAME="VERSION_MINOR"
PATCH_NAME="VERSION_PATCH"

MAJOR=0
MINOR=0
PATCH=0

RET=0

function REGEX_STR {
    eval SRC_STR="$1"
    eval DEC_STR="$2"

    # Check the dec worlds in the src string.
    result=$(echo $SRC_STR | grep "${DEC_STR}")
    if [[ "$result" != "" ]]
    then
        RET=1
    else
        RET=0
    fi
}

# Get the version form the version.h file.
while read line
do
    FINAL=${line: -1}

    # MAJOR Number
    RET=0
    REGEX_STR "\${line}" "\${MAJOR_NAME}"
    if [[ $RET == 1 ]]; then
        MAJOR=$FINAL
        RET=0
    fi

    # MINOR Number
    RET=0
    REGEX_STR "\${line}" "\${MINOR_NAME}"
    if [[ $RET == 1 ]]; then
        MINOR=$FINAL
        RET=0
    fi

    # PATCH Number
    RET=0
    REGEX_STR "\${line}" "\${PATCH_NAME}"
    if [[ $RET == 1 ]]; then
        PATCH=$FINAL
        RET=0
    fi
done < 'version/version.h'

# Get the cmake build lib version.
cd build
arm-none-linux-gnueabi-strip libs/lib/lib$LIB_NAME.so.$MAJOR.$MINOR.$PATCH
cd libs/lib/
tar -cvzf lib$LIB_NAME.tar.gz lib$LIB_NAME.so*