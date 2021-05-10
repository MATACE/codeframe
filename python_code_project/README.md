# Reference
Please visit [目录结构](https://marlous.github.io/2019/04/03/Python-%E8%BD%AF%E4%BB%B6%E9%A1%B9%E7%9B%AE%E6%96%87%E4%BB%B6%E7%BB%93%E6%9E%84%E7%BB%84%E7%BB%87/)

# Create Requirements
```bash
pip freeze > requirements.txt    # create requirements.txt
pip install -r requirements.txt  # install need package by requirements.txt
```

# API Document
Please visit [API文档生成]()

```bash
sphinx-quickstart
```

## API conf.py
```python
# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
sys.path.insert(0, os.path.abspath('../..'))
sys.path.insert(0, os.path.abspath('../src'))

# -- Project information -----------------------------------------------------

project = 'pro'
copyright = '2021, hxq'
author = 'hxq'

# The full version, including alpha/beta/rc tags
release = '1.0.0'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.doctest',
    'sphinx.ext.intersphinx',
    'sphinx.ext.todo',
    'sphinx.ext.coverage',
    'sphinx.ext.mathjax',
    'sphinx.ext.napoleon',
    'sphinx_rtd_theme'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
# html_theme = 'alabaster'
html_theme = 'sphinx_rtd_theme'
html_theme_options = {
    'canonical_url': '',
    # 'analytics_id': 'UA-XXXXXXX-1',  # Provided by Google in your dashboard
    'logo_only': False,
    'display_version': True,
    'prev_next_buttons_location': 'bottom',
    'style_external_links': False,
    # 'vcs_pageview_mode': '',
    # 'style_nav_header_background': 'white',
    # Toc options
    'collapse_navigation': True,
    'sticky_navigation': True,
    'navigation_depth': 4,
    'includehidden': True,
    'titles_only': False
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
```

## index.rxt
```rest
.. pro documentation master file, created by
   sphinx-quickstart on Mon May 10 22:40:49 2021.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to pro's documentation!
===============================

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   modules # add this

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

```

## Cmd
```bash
生成rst文件，-o 后面跟的是保存rst文件的路径，你的index.rst文件在哪个目录，就指定哪个目录，然后最后面是代码路径
sphinx-apidoc -o ./source ../src # 根目录
# 生成HTML
# linux
make clean
make html
# windows
./make.bat clean
./make.bat html
```

# How To Use

## Main.py Test

```bash	
./build.sh r
```

##  Clear

```bash
./build.sh c
```

