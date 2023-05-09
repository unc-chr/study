#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np97.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

class Student(object):
    def __init__(self, name = "", id = "", score = "", grade = []):
        self.name = name
        self.id = id
        self.score = score
        self.grade = grade

    def print(self):
        print("""{}'s student number is {}, and """
        """his grade is {}. He submitted {} assignments, each """
        """with a grade of {}""".format(self.name, self.id, self.score, \
        len(self.grade), " ".join(self.grade)))

name = input()
id = input()
score = input()
grade_list = input().split()

niuniu = Student(name, id, score, grade_list)
niuniu.print()