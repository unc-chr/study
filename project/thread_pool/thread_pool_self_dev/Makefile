

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

all:main test

main: test_main.cpp thread_pool.cpp task.cpp result.cpp thread.cpp
	${CPP} $^ ${CPPFLAGS} -pthread -o $@.out

test:test_any test_semaphore test_thread

test_any:test_any.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

test_semaphore:test_semaphore.cpp
	${CPP} $^ ${CPPFLAGS} -pthread -o $@.out

test_thread:test_thread.cpp thread.cpp
	${CPP} $^ ${CPPFLAGS} -pthread -o $@.out

.PHONY:clean
clean:
	rm *.out