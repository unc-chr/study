

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240530
#   Brife：
#
#================================================================

CC=gcc
DEP_DIR="../wrapped_func"

all:web

web:epoll_web.c
	${CC} $^ ${DEP_DIR}/wrap_sys.c pub.c -o $@.out

.PHONY:clean
clean:
	rm *.out