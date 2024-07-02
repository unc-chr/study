#!/bin/bash

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：sync.sh
#   Author：leekaihua
#   Date：20240701
#   Brife：
#
#================================================================

make libmytest
sudo cp my_test.h /usr/local/include/lee/test/
sudo cp libmytest.so /usr/local/mylib/
sudo /sbin/ldconfig