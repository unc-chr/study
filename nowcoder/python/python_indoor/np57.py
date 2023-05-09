#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np57.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

food_list = ['apple', 'ice cream', 'watermelon', 'chips', 'hotdogs', 'hotpot']

while food_list:
    food_list.pop()
    print(food_list)