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

all:test

test: tv ts tq

tv:test_vector.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -lmyexception -o $@.out

ts:test_string.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

tq: test_queue.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -lmyexception -o $@.out

.PHONY:clean
clean:
	rm *.out
