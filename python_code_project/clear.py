#!/bin/usr/python
# coding=utf-8

import os
import shutil

from src.clear.path_union import PathUnion


def clear():
    path = PathUnion(os.getcwd() + "/src")
    path.rm_child_regex_dirs("__pycache__")
    path.rm_child_regex_files("pyc")

if __name__ == "__main__":
    clear()


