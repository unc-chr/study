#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np72.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

name_list = input().split()
language_list = input().split()
dict_name_language = dict(zip(name_list, language_list))
print(dict_name_language)