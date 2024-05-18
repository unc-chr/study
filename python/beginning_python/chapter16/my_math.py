#!usr/bin/env python
# -*- coding:utf-8 -*-
""" docstring
"""
#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   File：my_math.py
#   Author：leekaihua
#   Date：2023年03月31日
#   Brife：
#
#================================================================


def square(p_x):
    """
    >>> square(2)
    4
    >>> square(3)
    9
    """
    return p_x * p_x

def product(p_x, p_y):
    """
    >>> product(1, 2)
    2
    >>> product(4, 7)
    28
    """
    return p_x * p_y


if __name__ == "__main__":
    product(1, 2)
