#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np100.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

class Coordinate(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "({}, {})".format(self.x, self.y)

    def __add__(self, coor):
        return Coordinate(self.x + coor.x, self.y + coor.y)

x1, y1 = [int(x) for x in input().split()]
x2, y2 = [int(x) for x in input().split()]
c1 = Coordinate(x1, y1)
c2 = Coordinate(x2, y2)
print(c1 + c2)