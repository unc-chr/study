

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240611
#   Brife：
#
#================================================================


all:main

main:test_main.cpp a.cpp b.cpp
	g++ $^ -std=c++11 -o $@.out

.PHONY:clean
clean:
	rm *.out