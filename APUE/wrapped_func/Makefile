

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240524
#   Brife：
#
#================================================================

all: wrap_sys wrap_sig wrap_err

wrap_sys: wrap_sys.c
	gcc $^ -c -o $@.o

wrap_sig: wrap_sig.c
	gcc $^ -c -o $@.o

wrap_err: wrap_err.c
	gcc $^ -c -o $@.o

.PHONY:clean
clean:
	rm *.o
