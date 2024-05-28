

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240528
#   Brife：
#
#================================================================

CC=gcc
CFLAGS=-Wall -g -pthread

all: thread_pool test

thread_pool: thread_pool.c job.c loop_array.c
	gcc $^ ${CFLAGS} -o $@.out

test: test_queue_loop

test_queue_loop: test_queue_loop.c loop_array.c job.c
	${CC} $^ -g -o $@.out

.PHONY: clean
clean:
	rm *.out
