

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240602
#   Brife：
#
#================================================================


CPP=g++
CPPFLAGS=-Wall -g -std=c++11

all: tdc

tdc: test_default_constructor.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out