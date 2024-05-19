

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：2024年05月17日
#   Brife：
#
#================================================================

SRC = $(wildcard ./*.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
TARGET = test

${TARGET}: ${OBJS}
	gcc $^ -o $@

%.o:%.c
	gcc $^ -c -o $@

.PHONY:clean
clean:
	rm -rf ${OBJS} ${TARGET}
