#!/bin/bash
ulimit -c unlimited
ulimit -n 65535
PROXY_HOME=`dirname $0`
cd ${PROXY_HOME}

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./demo
# Detect code memory leaks bash shell cmd
# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./demo