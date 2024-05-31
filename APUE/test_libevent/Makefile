

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240529
#   Brife：
#
#================================================================

CC=gcc

all: test server

server: libevent_server.c
	${CC} $^ -o $@.out	

test: test_libevent_install

test_libevent_install: test_libevent_install.c
	${CC} $^ -levent -o $@.out

.PHONY:clean
clean:
	rm *.out