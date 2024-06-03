

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

all:tsp tlr

tsp: test_smart_ptr.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

tlr: test_loop_reference.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

tlrS: test_loop_reference_SharedPtr.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out