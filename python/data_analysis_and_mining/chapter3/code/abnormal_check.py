#!usr/bin/env python3
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2023 Goldman Ltd. All rights reserved.
#   
#   File：abnormal_check.py
#   Author：leekaihua
#   Date：2023年04月28日
#   Brife：
#
#================================================================

import os
import pandas as pd
import matplotlib.pyplot as plt

file_dir = os.path.dirname(os.path.abspath(__file__))
root_dir = os.path.join(file_dir, "..")
data_dir = os.path.join(root_dir, "data")
catering_sale = os.path.join(data_dir, "catering_sale.xls")

if __name__ == "__main__":
    data = pd.read_excel(catering_sale, index_col = u'日期')
    print(data.describe())

    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False
    plt.figure()
    p = data.boxplot(return_type = 'dict')
    x = p['fliers'][0].get_xdata()
    y = p['fliers'][0].get_ydata()
    y.sort()

    for i in range(len(x)):
        if i > 0:
            plt.annotate(y[i], xy = (x[i], y[i]), 
                         xytext = (x[i] + 0.05 - 0.8/(y[i] - y[i - 1]), y[i]))
        else:
            plt.annotate(y[i], xy = (x[i], y[i]), xytext = (x[i] + 0.08, y[i]))
        
    plt.show()
