/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap.c
*   Author：leekaihua
*   Date：20240524
*   Brife：
*



*/
#ifndef __WRAP_SYS_H
#define __WRAP_SYS_H

#include "wrap_err.h"

#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int Inet_pton(int af, const char* src, void* dst);
const char* Inet_ntop(int af, const void* src, char* dst, socklen_t size);

int Socket(int family, int type, int protocol);
int Connect(int sock_fd, const struct sockaddr* addr, socklen_t addrlen);

int Bind(int sock_fd, const struct sockaddr* addr, socklen_t addrlen);
int Listen(int fd, int backlog);
int Accept(int sock_fd, struct sockaddr* addr, socklen_t* addrlen);

ssize_t Read(int fd, void* buf, size_t count);
ssize_t Write(int fd, const void* buf, size_t count);

// read n bytes
ssize_t Readn(int fd, void* buf, size_t n);
// write n bytes
ssize_t Writen(int fd, void* buf, size_t n);

static ssize_t Read_char(int fd, char* ret_char);

// read char by char until reached '\n'
ssize_t Readline(int fd, void* buf, size_t maxlen);

int tcp4_bind(short port, const char* IP);

#endif