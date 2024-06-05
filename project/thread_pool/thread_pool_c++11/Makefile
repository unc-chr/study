

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

all: threadpool ttp

ttp: test_thread_pool.cpp
	${CPP} $^ ${CPPFALGS} threadpool.o -pthread -o $@.out

threadpool:threadpool.cpp
	${CPP} $^ ${CPPFALGS} -pthread -c -o $@.o

.PHONY:clean
clean:
	rm *.o
	rm *.out