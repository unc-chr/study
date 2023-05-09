#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np103.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

import re

tele_num = input()
pattern_str = r"([0-9\-]+) "
pattern = re.compile(pattern_str)
result = re.match(pattern, tele_num)
print(result.group(1))