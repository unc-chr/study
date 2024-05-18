#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np101.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

import re

web_url = input()

pattern_original = "https://www+"
pattern = re.compile(pattern_original)
matched_obj = re.match(pattern, web_url)
print(matched_obj.span())