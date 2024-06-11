

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240601
#   Brife：
#
#================================================================

CPP=g++
CPPFALGS=-Wall -g -std=c++17

all: ttp

ttp: test_thread_pool.cpp threadpool.cpp result.cpp task.cpp thread.cpp
	${CPP} $^ ${CPPFALGS} -pthread -o $@.out

.PHONY:clean
clean:
	rm *.out
	rm *.o