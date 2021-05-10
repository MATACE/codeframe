#!/usr/bin/python
# coding=utf-8

import logging
from . import mode1
from . import mode2
from .log import LogOp

def func():
    # Init the logging
    init_log()

    mode1.mode1()
    mode2.mode2()

def init_log():
    """
    Init the python user log

    Args:
        None
    Return:
        None
    """
    log_op = LogOp()
    log_op.config_log(logging.DEBUG)