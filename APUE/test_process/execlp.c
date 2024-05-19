/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：execlp.c
*   Author：leekaihua
*   Date：2024年05月19日
*   Brife：
*



*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("hello itcast\n");

    // 第一个参数是文件名，其他是变参
    // execlp("ls", "ls", "-l", "--color=auto", "/home/lkh", NULL);
    // 第一个参数是路径名，其他是变参，最后是 NULL
    execl("/bin/ls", "ls", "-l", "--color=auto", "/home/lkh", NULL);
    printf("hello world\n");
    return 0;
}