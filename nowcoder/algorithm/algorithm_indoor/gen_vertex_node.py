#!usr/bin/env python3
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：gen_vertex_node.py
#   Author：leekaihua
#   Date：2023年05月06日
#   Brife：
#
#================================================================

import random

vertex = []
n = 5000
for i in range(n):
    temp = []
    temp.append(random.randint(1, 5000))
    temp.append(random.randint(1, 5000))
    temp.append(random.randint(1, 50000))
    vertex.append(temp)

for i in range(n):
    print("{} {} {}".format(vertex[i][0], vertex[i][1], vertex[i][2]))