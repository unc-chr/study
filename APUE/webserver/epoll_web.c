/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：epoll_web.c
*   Author：leekaihua
*   Date：20240530
*   Brife：
*       webserver 框架
*/

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <sys/stat.h>

#include "../wrapped_func/wrap_sys.h"
#include "pub.h"

#define PORT 8899
#define IP "192.168.3.143"

void send_header(int cfd, int code, char* info, char* filetype, int length) {
    // 发送状态行
    char buf[1024] = "";
    int len = 0;
    len = sprintf(buf, "HTTP/1.1 %d %s\r\n", code, info);
    // 下面这种用法是有问题的，如果buf中出现了 \0，那么长度计算就会出错
    // send(cfd, buf, strlen(buf));
    send(cfd, buf, len, 0);
    // 发送消息头
    len = sprintf(buf, "Content-Type:%s\r\n", filetype);
    send(cfd, buf, len, 0);
    if (length > 0) {
        len = sprintf(buf, "Content-Length:%d\r\n", length);
        send(cfd, buf, len, 0);
    }
    // 发送空行
    send(cfd, "\r\n", 2, 0);
}

void send_file(int cfd, char* path, struct epoll_event* event, int epfd, int close_fd) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open error");
        return;
    }
    char buf[1024] = "";
    int len = 0;
    while (1) {
        len = read(fd, buf, sizeof(buf));
        if (len < 0) {
            perror("read error");
            break;
        } else if (len == 0) {
            break;
        } else {
            send(cfd, buf, len, 0);
        }
    }
    close(fd);
    // 关闭 cfd，下树
    // 这里解决的是网页加载完成后，还在持续加载的问题
    // client 误以为还有内容没有传送完毕，因此一直在等待加载。
    if (close_fd) {
        close(event->data.fd);
        epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, event);
    }
}

void read_client_request(int epfd, struct epoll_event* event) {
    // 先读取请求行，然后读取其他行，避免其他行待在缓冲区中
    char buf[1024] = "";
    int n = Readline(event->data.fd, buf, sizeof(buf));
    if (n < 0) {
        // 下树
        printf("close or err\n");
        epoll_ctl(epfd, EPOLL_CTL_DEL, event->data.fd, event);
        close(event->data.fd);
        return;
    }
    printf("%s\n",  buf);
    
    char tmp[1024] = "";
    int ret = 0;
    // 读取并抛弃其他行
    while ((ret = Readline(event->data.fd, tmp, sizeof(tmp))) > 0);
    printf("read ok\n");

    // 解析请求 GET /a.txt HTTP/1.1\R\N
    char method[256] = "";
    char content[256] = "";
    char protocol[256] = "";
    sscanf(buf, "%[^ ] %[^ ] %[^ \r\n]", method, content, protocol);
    printf("[%s] [%s] [%s]\n", method, content, protocol);
    // 判断是否为 get 请求，get 请求才进行处理
    if (strcasecmp(method, "get") == 0) {
        // 跳过 /a.txt 的第一个斜杠
        // 得到浏览器请求的文件，如果对方没有请求文件，默认是请求当前目录
        char* strfile = content + 1;
        printf("before decode: %s\n", strfile);
        strdecode(strfile, strfile);
        printf("after decode: %s\n", strfile);
        // 如果没有指定请求的文件，默认请求当前目录
        if (*strfile == 0) {
            strfile = "./";
        }
        struct stat s;
        // 判断文件是否存在，如果不存在
        if (stat(strfile, &s) < 0) {
            printf("file not found\n");
            // 先发送报头(状态行 消息头 空行)
            send_header(event->data.fd, 404, "NOT FOUND", get_mime_type("*.html"), 0);
            // 发送文件 error.html
            send_file(event->data.fd, "error.html", event, epfd, 1);
        } else {
            if (S_ISREG(s.st_mode)) {   // 请求的是普通的文件
                printf("is requesting a regular file\n");
                // 先发送报头(状态行 消息头 空行)
                send_header(event->data.fd, 200, "OK", get_mime_type(strfile), s.st_size);
                // 发送文件
                send_file(event->data.fd, strfile, event, epfd, 1);
            } else if (S_ISDIR(s.st_mode)) {   // 请求的是目录
                printf("is requesting a directory\n");
                send_header(event->data.fd, 200, "OK", get_mime_type(".html"), 0);
                // 发送头部, 也就是 header.html
                send_file(event->data.fd, "dir_header.html", event, epfd, 0);
                // 发送列表，也就是目录下的内容
                struct dirent** my_list = NULL;
                int n = scandir(strfile, &my_list, NULL, alphasort);
                char buf[1024] = "";
                int len = 0;
                for (int i = 0; i < n; i++) {
                    printf("%s\n", my_list[i]->d_name);
                    if (my_list[i]->d_type == DT_DIR) {
                        // 如果是个目录，超链接需要加上 /，这样浏览器知道进入一个目录，并在后续的请求链接中加上 /dir
                        len = sprintf(buf, "<li><a href=%s/>%s</a></li>", my_list[i]->d_name, my_list[i]->d_name);
                    } else {
                        len = sprintf(buf, "<li><a href=%s>%s</a></li>", my_list[i]->d_name, my_list[i]->d_name);
                    }
                    send(event->data.fd, buf, len, 0);
                    free(my_list[i]);
                }
                free(my_list);
                // 发送尾部
                send_file(event->data.fd, "dir_tail.html", event, epfd, 1);
            }
        }
    }
}

int main() {
    // 切换工作目录，目的是打开 http 文件的时候，不用再加路径
    // 获取当前目录的工作路径
    char pwd_path[256] = "";
    char* path = getenv("PWD");
    strcpy(pwd_path, path);
    strcat(pwd_path, "/web-http");
    chdir(pwd_path);
    // create and bind
    int lfd = tcp4_bind(PORT, IP);
    if (lfd < 0) {
        return 1;
    }
    printf("tcp4bind done\n");

    // listen
    Listen(lfd, 128);
    printf("listen done\n");

    // create rb tree
    int epfd = epoll_create(1); 
    // add lfd to rb tree
    struct epoll_event ev;
    ev.data.fd = lfd;
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    printf("epoll rb tree initialization done.\n");
    // epoll event array
    struct epoll_event events[1024];
    // while
    while (1) {
        int n_ready = epoll_wait(epfd, events, 1024, -1);
        printf("epoll wait %d events.\n", n_ready);
        if (n_ready < 0) {
            perror("epoll_create error");
            break;
        } else {
            for (int i = 0; i < n_ready; i++) {
                if (events[i].data.fd == lfd && events[i].events & EPOLLIN) {
                    struct sockaddr_in cli_addr;
                    socklen_t len = sizeof(cli_addr);
                    int cfd = Accept(lfd, (struct sockaddr*)&cli_addr, &len, 1);
                    // 设置 cfd 为非阻塞
                    int flag = fcntl(cfd, F_GETFL);
                    flag |= O_NONBLOCK;
                    fcntl(cfd, F_SETFL, flag);
                    // add new created cfd to rb tree
                    ev.data.fd = cfd;
                    ev.events = EPOLLIN;
                    epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                    printf("add new created cfd to rb tree done.\n");
                } else if (events[i].events & EPOLLIN)  {
                    printf("cfd request\n");
                    read_client_request(epfd, &events[i]);
                }
            }
        }
    }

    // recycle resource
    return 0;
}
