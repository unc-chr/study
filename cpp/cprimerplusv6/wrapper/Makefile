

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240604
#   Brife：
#
#================================================================
CPP=g++
CPPFLAGS=-Wall -g -std=c++11

all: bind

bind: test_bind.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out