#!usr/bin/env python3
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：test_matplotlib.py
#   Author：leekaihua
#   Date：2023年04月28日
#   Brife：
#
#================================================================


import os
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    x = np.linspace(0, 10, 1000)
    y = np.sin(x) + 1
    z = np.cos(x**2) + 1

    plt.figure(figsize = (8, 4))
    plt.plot(x, y, label = '$\sin x+1$', color = 'red', linewidth = 2)
    plt.plot(x, z, 'b--', label = '$\cos x^2+1$')
    plt.xlabel('Time(s)')
    plt.ylabel('Volt')
    plt.title('A Simple Examle')
    plt.ylim(0, 2.2)
    plt.legend()
    plt.show()