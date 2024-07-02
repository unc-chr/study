#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240629
#   Brife：
#
#================================================================

CPP=g++
CPP_DEBUG_FLAGS=-Wall -g -std=c++11
CPP_layout_FLAGS=-fdump-lang-class

all: test

test:test 

tvbc: test_virtual_base_class.cpp
	${CPP} $^ ${CPP_layout_FLAGS} -c
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

tdi: test_diamond_inheritance.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out
tdi2: test_diamond_inheritance_v2.cpp
	${CPP} $^ ${CPP_DEBUG_FLAGS} -o $@.out

.PHONY:clean
clean:
	rm *.out