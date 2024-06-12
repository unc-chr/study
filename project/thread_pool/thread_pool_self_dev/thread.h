/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread.h
*   Author：leekaihua
*   Date：20240612
*   Brife：
*



*/
#pragma once

#include <functional>
#include <thread>

class Thread {
public:
    using thread_func = std::function<void(int)>;
    Thread(thread_func func);
    ~Thread();
    void start();
    // 线程的id
    int get_id();
private:
    // 函数指针，指向线程的执行函数
    thread_func func_;
    // 线程id
    int thread_id_;
    static int count;
};