#include "set_dzlog.h"

bool dlog_init()
{
    dlog_setting.rc = dzlog_init(ZLOG_CONF_PAHT, ZLOG_NAME);
    
    if (dlog_setting.rc) {
        printf("%s->%d zlog init failed\n", __func__, __LINE__);
        return false;
    }

    return true;
}

void dlog_destroy()
{
    zlog_fini();
}