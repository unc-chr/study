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

test:tnd 

tnd: test_new_delete.cpp
	${CPP} $^ -o $@.out

.PHONY:clean
clean:
	rm *.out