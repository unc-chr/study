/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap.c
*   Author：leekaihua
*   Date：20240524
*   Brife：
*



*/
#include "wrap_sys.h"

int Inet_pton(int af, const char* src, void* dst) {
    int ret = -1;
    ret = inet_pton(af, src, dst);
    if (1 == ret) {
        return ret;
    } else if (0 == ret) {
        printf("inet_pton error: IP address illegal.\n");
        exit(1);
    } else if (-1 == ret) {
        perror("inet_pton error");
    }
}

const char* Inet_ntop(int af, const void* src, char* dst, socklen_t size) {
    const char* dest = inet_ntop(af, src, dst, size);
    if (NULL == dest) {
        perror("inet_ntop error");
    }
    return dest;
}

int Socket(int family, int type, int protocol) {
    int ret;
    if ((ret = socket(family, type, protocol)) < 0) {
        perror("socket error");
    }
    return ret;
}

int Connect(int sock_fd, const struct sockaddr* addr, socklen_t addrlen) {
    int ret;
    if ((ret = connect(sock_fd, addr, addrlen)) < 0) {
        perror("connect error");
    }
    return ret;
}

int Bind(int sock_fd, const struct sockaddr* addr, socklen_t addrlen) {
    int ret;
    if ((ret = bind(sock_fd, addr, addrlen)) < 0) {
        perror("bind error");
    }
    return ret;
}

int Listen(int fd, int backlog) {
    int ret;
    if ((ret = listen(fd, backlog)) < 0) {
        perror("listen error");
    }
    return ret;
}

// return: file descriptor
int Accept(int sock_fd, struct sockaddr* addr, socklen_t* addrlen) {
    int cfd;
again:
    if ((cfd = accept(sock_fd, addr, addrlen)) < 0) {
        // if connection aborted or interrupted function call,
        // don't exit, retry. reference man errno.
        if ((errno == ECONNABORTED) || (errno == EINTR)) {
            goto again;
        } else {
            perror("accept error");
        }
    }
    return cfd;
}

ssize_t Read(int fd, void* buf, size_t count) {
    ssize_t n;

    memset(buf, 0, sizeof(buf));
again:
    if ((n = read(fd, buf, count)) == -1) {
        if (errno == EINTR) {
            goto again;
        } else {
            return -1;
        }
    }
    return n;
}

ssize_t Write(int fd, const void* buf, size_t count) {
    ssize_t n = -1;
again:
    if ((n = write(fd, buf, count)) == -1) {
        if (errno == EINTR) {
            goto again;
        } else {
            return -1;
        }
    }
    return n;
}

// read n bytes
ssize_t Readn(int fd, void* buf, size_t n) {
    size_t nleft = n;    // number of left unread bytes
    ssize_t nread;    // number of read bytes
    char* curr = buf;
    memset(buf, 0, sizeof(buf));

    while (nleft > 0) {
        if ((nread = read(fd, buf, nleft)) < 0) {
            if (errno == EINTR) {
                nread = 0;
            } else {
                return -1;
            }
        } else if (nread == 0) {
            break;
        }
        nleft -= nread;
        curr += nread;
    }
    return n - nleft;
}

ssize_t Writen(int fd, void* buf, size_t n) {
    size_t nleft;
    ssize_t nwritten;
    const char* curr;

    curr = buf;
    nleft = n;

    while (nleft > 0) {
        if ((nwritten = write(fd, buf, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR) {
                nwritten = 0;
            } else {
                return -1;
            }
        }
        nleft -= nwritten;
        curr += nwritten;
    }
    return n - nleft;
}

static ssize_t Read_char(int fd, char* ret_char) {
    static int read_char;
    static char* curr_char_pos;
    static char read_buf[100];

    if (read_char <= 0) {
again:
        if ((read_char = read(fd, read_buf, sizeof(read_buf))) < 0) {
            if (errno == EINTR) {
                goto again;
            }
            return -1;
        } else if (read_char == 0) {
            return 0;
        }
        curr_char_pos = read_buf;
    }
    *ret_char = *curr_char_pos++;
    read_char--;

    return 1;
}

// read char by char until reached '\n'
ssize_t Readline(int fd, void* buf, size_t maxlen) {
    ssize_t read_char;
    ssize_t char_order;
    char c;
    char* curr = buf;
    for (char_order = 1; char_order < maxlen; char_order++) {
        if ((read_char = Read_char(fd, &c)) == 1) {
            *curr++ = c;
            if (c == '\n') {
                break;
            }
        } else if (read_char == 0) {
            *curr = 0;
            return char_order;
        } else {
            return -1;
        }
    }

    *curr = 0;
    return char_order;
}

int tcp4_bind(short port, const char* IP) {
    struct sockaddr_in serv_addr;
    int lfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    if (IP == NULL) {
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    } else {
        if (inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr) <= 0) {
            perror(IP);
            exit(1);
        }
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    Bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    return lfd;
}