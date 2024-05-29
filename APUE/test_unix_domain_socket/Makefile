

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：20240529
#   Brife：
#
#================================================================


all: server client

server: unix_domain_tcp_server.c
	gcc $^ -o $@.out

client: unix_domain_tcp_client.c
	gcc $^ -o $@.out

.PHONY:clean
clean:
	rm *.out