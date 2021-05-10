#!/bin/usr/python
# coding=utf-8

from setuptools import setup, find_packages

# 指定release
# python setup.py bdist_rpm --release=20200617

setup(
    # package name
    name = "package_demo",
    # version
    version = "1.0",
    # author
    author = "hxq",
    author_email = "xxx",
    description = "Pack Python Module",
    keywords="hello world example examples",
    python_requires = '>=3.8', # the python must be request version
    # url
    url="www.baidu.com",
    project_urls={
        # "Documentation": "https://docs.example.com/HelloWorld/",
        # "Source Code": "https://code.example.com/HelloWorld/",
    },
    classifiers=[
        # 'License :: OSI Approved :: Python Software Foundation License'
    ],

    # 通过setuptools.find_packages找到当前目录下有哪些包需要打包
    # packages = find_packages(where='.', exclude=('main', 'clear'), include=('./src',)),
    packages = find_packages(),
    # 函数的第一个参数用于指定在哪个目录下搜索包，参数exclude用于指定排除哪些包，参数include指出要包含的包
    # 安装过程中，需要安装的静态文件，如配置文件、service文件、图片等
    data_files=[
        ('', ['scripts/Makefile']), # '' 表示root package
        #('/usr/lib/systemd/system/', ['bin/*.service']),
        #('目录路径', [目录下的文件列表]),
               ],

    # 希望被打包的文件
    package_data={
        '':['*.py'],
        'src':['*']
        # 'bandwidth_reporter':['*.txt']
        # '目录路径' : [目录列表]
               },

    # 不打包某些文件
    exclude_package_data={
        # 'bandwidth_reporter':['*.txt']
        # '目录路径' : [目录列表]
               },

    install_requires=[          # 在安装模块时会自动安装依赖包
        # 'pyjokes>=0.3.0,!0.4.0,<0.5.0'
        # pyjokes==0.5.0
        # pyjokes>=0.3.0
    ],
    extras_require={       # 添加了可选安装的依赖 package不会自动安装,表示该模块会依赖这些包
                           # 但是这些包通常不会使用到，只有当你深度使用模块时，需要你手动安装
        # 'interactive': ['matplotlib>=2.2.0,<3.0.0', 'jupyter']
        # 'PDF':  ["ReportLab>=1.2", "RXP"],
        # 'reST': ["docutils>=0.3"],
    },
    entry_points={
        # 用来支持自动生成脚本，安装后会自动生成/usr/bin/foo的可执行文件
        # 该文件入口指向foo/main.py的main函数
        'console_scripts': [
            #'foo = foo.main:main',
            #'bar=foo.entry:main',
        ]
    },
    py_modules=[  # 在package之外添加两个独立的 module
        # 'main', 脚本的执行
        # 'clear' 清楚python生成的临时模块
    ],
    zip_safe=False
)