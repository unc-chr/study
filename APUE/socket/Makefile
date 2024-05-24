

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
WRAP_DIR=/home/lkh/study/APUE/wrapped_func

all: single_process multi_process

single_process: tcp_server tcp_client

tcp_server: tcp_server.c
	${CC} $^ -o $@.out

tcp_client: tcp_client.c
	${CC} $^ -o $@.out

multi_process: tcp_client tcp_server_multi_process

tcp_server_multi_process: tcp_server_multi_process.c
	${CC} $^ ${WRAP_DIR}/wrap_sys.c ${WRAP_DIR}/wrap_err.c ${WRAP_DIR}/wrap_sig.c -o $@.out

.PHONY:clean
clean:
	rm *.out
