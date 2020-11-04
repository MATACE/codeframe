#!/usr/bin/python
# coding=utf-8

import os
import re
import shutil

class PathUnion():
    def __init__(self, root_path):
        self.root_path_ = root_path
    
    def rm_child_regex_dirs(self, *regexs):
        """ Rm the dir of tree follower end character is regexs all dir.
            example: rm /abc/xyz/123__pycache__ the dir of all file
        """
        # TODO:
        # Need the try except do if the regex not the right character

        self.roots_list = []     
        for root, dirs, files in os.walk(self.root_path_):
            self.roots_list.append(root)

        for regex in regexs:
            regex_str = regex
            end_str = '$'
            regex_str += end_str
            regex = re.compile(regex_str)
            
            for root in self.roots_list:
                ret = regex.search(root)
                # The no search the ret will be None
                # when the search find the ret will be a match object
                if ret != None:
                    shutil.rmtree(root)

    def rm_child_regex_files(self, *regexs):
        """ Rm thi files of the follower end character is regexs all file.
            example: rm /abc/xyz/my_func.pyc
        """        
        
        for root, dirs, files in os.walk(self.root_path_):
            # for dir in dirs:
            #      = root + "/" + dir
            for file in files:
                file_path = root + "/" + file
                # TODO:
                # Need the try except do if the regex not the right character
                for regex in regexs:
                    regex_str = regex
                    end_str = '$'
                    regex_str += end_str
                    regex = re.compile(regex_str)
                
                    ret = regex.search(file_path)
                    # The no search the ret will be None
                    # when the search find the ret will be a match object
                    if ret != None:
                        os.unlink(file_path)