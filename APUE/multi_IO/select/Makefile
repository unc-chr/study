

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

select: select.c
	${CC} $^ ${WRAP_DIR}/wrap_sys.c ${WRAP_DIR}/wrap_sig.c -o $@.out

.PHONY:clean
clean:
	rm *.out
