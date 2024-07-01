

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

test: to th tvpf

to: test_override.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

th: test_hide.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

tvpf: test_virtual_private_func.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.o
	rm *.out