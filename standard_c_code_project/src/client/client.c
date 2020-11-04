#include "client.h"

void test()
{
    int errno = 3;

    dlog_init();

    dzlog_info("Errno num is: %d", errno);
    
}