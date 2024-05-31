/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_libevent_install.c
*   Author：leekaihua
*   Date：20240529
*   Brife：
*



*/

#include <stdio.h>
#include <event.h>

int main() {
    const char** methods = event_get_supported_methods();
    int i = 0;
    // 打印 libevent 支持的方法
    for (int i = 0; methods[i] != NULL; i++) {
        printf("%s\n", methods[i]);
    }
    // 打印当前平台支持的方法
    struct event_base* base = event_base_new();
    printf("current platform support: %s\n", event_base_get_method(base));

    return 0;
}