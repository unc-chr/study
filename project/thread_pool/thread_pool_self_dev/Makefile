

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240610
#   Brife：
#
#================================================================

CPP=g++
CPPFLAGS=-Wall -g -std=c++14

all:any

any:test_any.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out