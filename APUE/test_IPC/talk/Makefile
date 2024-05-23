

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：2024年05月20日
#   Brife：
#
#================================================================


all: talkA talkB

talkA:talkA.c
	gcc $^ -o $@.o

talkB:talkB.c
	gcc $^ -o $@.o

.PHONY:clean
clean:
	rm -rf talkA.o talkB.o
