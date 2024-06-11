

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
CPPFLAGS=-Wall -g -std=c++17

all:any main

main: test_main.cpp thread_pool.cpp task.cpp result.cpp
	${CPP} $^ ${CPPFLAGS} -pthread -o $@.out

any:test_any.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out