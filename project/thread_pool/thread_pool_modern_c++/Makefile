

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
CPPFLAGS=-Wall -g

all: test

test: test_pool.cpp
	${CPP} $^ ${CPPFLAGS} -pthread -o $@.out

.PHONY:clean
clean:
	rm *.out