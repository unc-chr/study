

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
CPPFALGS=-Wall -g

all: threadpool test 

test: test_thread_pool.cpp
	${CPP} $^ threadpool.o -pthread ${CPPFALGS} -o $@.out

threadpool:threadpool.cpp
	${CPP} $^ ${CPPFALGS} -c -o $@.o

.PHONY:clean
clean:
	rm *.o
	rm *.out