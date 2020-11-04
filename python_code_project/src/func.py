#!/usr/bin/python
# coding=utf-8

import logging
from src.mode1 import mode1
from src.mode2 import mode2
from src.log   import LogOp


def func():
    # Init the logging
    init_log()

    mode1.mode1()
    mode2.mode2()

def init_log():
    log_op = LogOp()
    log_op.config_log(logging.DEBUG)