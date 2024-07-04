#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240701
#   Brife：
#
#================================================================

CPP=g++
CPPFLAGS=-std=c++11
CPP_DEBUG_FLAGS=-Wall -g -std=c++11
SHARED_FLAGS=-fPIC -shared

all:test shared

test: tcn

shared:complexnum

tcn:test_complex_number.cpp complex_number.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

complexnum: complex_number.cpp
	${CPP} $^ ${SHARED_FLAGS} -o lib$@.so

.PHONY:clean
clean:
	rm *.so
	rm *.out
