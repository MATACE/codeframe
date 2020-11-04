#!/usr/bin/python
#coding=utf-8

import logging
from logging import disable, log, logMultiprocessing
import threading
class SingletonType(type):
    _instance_lock = threading.Lock()
    def __call__(cls, *args, **kwargs):
        if not hasattr(cls, "_instance"):
            with SingletonType._instance_lock:
                if not hasattr(cls, "_instance"):
                    cls._instance = super(SingletonType, cls).__call__(*args, **kwargs)
        return cls._instance

class LogOp():
    __metaclass__ = SingletonType
    def __init__(self):
        pass
    
    def config_log(self, log_level, log_file_name="", log_file_mode="w+"):
        """ Set the logging level and log file name.

        Args:
            log_level (string): [description]
            log_file_name (string, ""): The save log file name. Defaults to "".
            log_file_mode (string, "w+"): The log file save mode. Defaults to "w+".
        """
        # logging.basicConfig(format='%(asctime)s - %(pathname)s[line:%(lineno)d] - %(levelname)s: %(message)s',
        #             level=logging.DEBUG)
        if log_file_name == "":
            logging.basicConfig(level = log_level,\
                format='%(levelname)s %(asctime)s [%(filename)s:%(lineno)d] %(message)s',\
                datefmt='%Y.%m.%d. %H:%M:%S'
                )
        else:
            logging.basicConfig(level = log_level,\
                format='%(levelname)s %(asctime)s [%(filename)s:%(lineno)d] %(message)s',\
                datefmt='%Y.%m.%d. %H:%M:%S',\
                log_file_name='parser_result.log',\
                filemode=log_file_mode
                )
    def disable_log(self, disable_level = logging.ERROR):
        logging.disable(disable_level)


