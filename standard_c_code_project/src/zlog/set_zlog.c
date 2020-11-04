#include "set_zlog.h"

bool log_init()
{
    log_setting.rc = zlog_init(ZLOG_CONF_PAHT);

    if (log_setting.rc) {
        printf("%s->%d zlog init failed\n", __func__, __LINE__);
        return false;
    }

    log_setting.c = zlog_get_category(ZLOG_NAME);

    if (!log_setting.c) {
        printf("%s->%d zlog get cat fail\n", __func__, __LINE__);
        zlog_fini();
        log_setting.c = NULL;
        return false;
    }

    return true;
}

bool log_destroy()
{   
    if (zlog_fini != NULL) {
        zlog_fini();
        return true;
    }

    return false;
}