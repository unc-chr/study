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

all: test libmyexception

test: my_exception.cpp test_my_exception.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

libmyexception: my_exception.cpp
	${CPP} $^ ${SHARED_FLAGS} -o $@.so

test_with_so: test_my_exception.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -lmyexception -o $@.out

.PHONY:clean
clean:
	rm *.out
	rm *.so
