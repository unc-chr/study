

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240629
#   Brife：
#
#================================================================

CPP=g++
CPPFLAGS=-Wall -g -std=c++11

all: test

test: tsc tdc

tsc: test_static_cast.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

tdc: test_dynamic_cast.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.o
	rm *.out