

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：2024年05月19日
#   Brife：
#
#================================================================


all: read write

read: read.c
	gcc $^ -o $@.out

write: write.c
	gcc $^ -o $@.out

.PHONY:clean
	rm -rf read.out write.out