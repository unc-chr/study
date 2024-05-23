

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240523
#   Brife：
#
#================================================================

CC=gcc
CFLAGS=-o

all: tcp_server tcp_client

tcp_server: tcp_server.c
	${CC} $^ -o $@.out

tcp_client: tcp_client.c
	${CC} $^ -o $@.out

.PHONY:clean
clean:
	rm tcp_server.out tcp_client.out