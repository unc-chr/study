

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240605
#   Brife：
#
#================================================================


CPP=g++
CPPFLAGS=-Wall -g -std=c++11

all: test

test: tr trrbc trrv1 tpf

tr:test_rvalue.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

tpf:test_perfect_forward.cpp
	${CPP} $^ ${CPPFLAGS} -o $@.out

trrbc:test_rvalue_ref_bad_case.cpp
	${CPP} $^ ${CPPFLAGS} -fno-elide-constructors -o $@.out

trrv1:test_rvalue_ref_v1.cpp
	${CPP} $^ ${CPPFLAGS} -fno-elide-constructors -o $@.out

.PHONY:clean
clean:
	rm *.out