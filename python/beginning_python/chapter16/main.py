#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：main.py
#   Author：leekaihua
#   Date：2023年03月31日
#   Brife：
#
#================================================================

import doctest
import my_math

if __name__ == "__main__":
    doctest.testmod(my_math)

    result_product = my_math.product(1, 2)
    result_square = my_math.square(3)
    print(result_product)
    print(result_square)