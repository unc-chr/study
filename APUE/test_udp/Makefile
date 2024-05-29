

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

all: udp_server udp_client

udp_server: udp_server.c
	${CC} $^ -o $@.out

udp_client: udp_client.c
	${CC} $^ -o $@.out

.PHONY:clean
clean:
	rm *.out