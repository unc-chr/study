#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240630
#   Brife：
#
#================================================================
CPP=g++
CPPFLAGS=-std=c++11
CPP_DEBUG_FLAGS=-Wall -g -std=c++11
SHARED_FLAGS=-fPIC -shared

all: test libmytest

test: my_test.cpp test_my_test.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

libmytest: my_test.cpp
	${CPP} $^ ${SHARED_FLAGS} -o $@.so

test_with_so: test_my_test.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -lmytest -o $@.out

.PHONY:clean
clean:
	rm *.out
	rm *.so