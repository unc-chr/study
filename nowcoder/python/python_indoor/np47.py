#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：np47.py
#   Author：leekaihua
#   Date：2023年04月01日
#   Brife：
#
#================================================================

gpa = {
    "A": 4.0,
    "B": 3.0,
    "C": 2.0,
    "D": 1.0,
    "F": 0
}
grade_dict = {}

level = ""
while True:
    line = input() 
    if line in gpa:
        if line not in grade_dict:
            grade_dict[line] = []
        level = line
    elif line != "False":
        grade_dict[level].append(int(line))
        level = ""
    else:
        break

sum_socre = 0.0
sum_grade = 0
for k, v in grade_dict.items():
    sum_xuefen = 0
    for ele in v:
        sum_xuefen += ele
    sum_grade += sum_xuefen
    sum_socre += sum_xuefen * gpa[k]

result = sum_socre / sum_grade
print("{:.2f}".format(result))