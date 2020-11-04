#ifndef SET_ZLOG_H
#define SET_ZLOG_H

#include <stdio.h>
#include <stdbool.h>

#include "zlog.h"

#define ZLOG_CONF_PAHT  "../../libs/x64/zlog/conf/zlog.conf"
#define ZLOG_NAME       "set_log"

struct log {
    int rc;
    zlog_category_t *c;
};

static struct log log_setting;

bool log_init();
bool log_destroy();

#endif // SET_ZLOG_H