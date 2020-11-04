#ifndef SET_D_ZLOG_H
#define SET_D_ZLOG_H

#include <stdio.h>
#include <stdbool.h>

#include "zlog.h"

#define ZLOG_CONF_PAHT  "../../libs/x64/zlog/conf/zlog.conf"
#define ZLOG_NAME       "set_log"

struct dlog {
    int rc;
};

static struct dlog dlog_setting;

bool dlog_init();
void dlog_destroy();

#endif // SET_D_ZLOG_H