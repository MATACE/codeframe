#!/bin/sh
# If the valgrind is save in the USB flash disk
# mount /dev/sdb4 /mnt
# export VALGRIND_LIB=/mnt/valgrind/lib/valgrind
# export PATH=$PATH:/mnt/valgrind/bin

ulimit -c unlimited
ulimit -n 65535
PROXY_HOME=`dirname $0`
cd ${PROXY_HOME}

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

valgrind --tool=memcheck --leak-check=full $1