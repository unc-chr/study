#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240624
#   Brife：
#
#================================================================

CPP=g++
CPPFLAGS=-Wall -g -std=c++11

all: test

test:tfc tccc

tfc: test_func_call.cpp
	${CPP} $^ -o $@.out

tccc: test_cpp_call_c.cpp
	gcc sum.c -c -o sum.o
	${CPP} $^ sum.o ${CPPFLAGS} -o $@.out

tccc1: test_c_call_cpp1.cpp
	g++ func.cpp -c -o func.o
	gcc $^ func.o -o $@.out

.PHONY:clean
clean:
	rm *.out