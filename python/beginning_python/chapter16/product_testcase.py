#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：product_testcase.py
#   Author：leekaihua
#   Date：2023年03月31日
#   Brife：
#
#================================================================

import unittest
import my_math

class ProductTestCase(unittest.TestCase):
    """
    my_math 的测试类
    """
    def test_integers(self):
        """ 
        测试整数乘法
        """
        for x in range(-10, 10):
            for y in range(-10, 10):
                p = my_math.product(x, y)
                self.assertEqual(p, x * y, "Integer multiplication failed")

    def test_foats(self):
        """
        测试浮点数乘法
        """
        for x in range(-10, 10):
            for y in range(-10, 10):
                x = x / 10
                y = y / 10
                p = my_math.product(x, y)
                self.assertEqual(p, x * y, "Float multiplication failed")

if __name__ == "__main__":
    unittest.main()
