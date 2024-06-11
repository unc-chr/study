/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread.cpp
*   Author：leekaihua
*   Date：20240612
*   Brife：
*



*/
#include "thread.h"

int Thread::count = 0;

// TODO: 为什么这么构造在线程池中是有问题的，
// Thread::Thread(thread_func func) {
//     func_ = func;
//     count++;
//     thread_id_ = count;
// }

Thread::Thread(thread_func func)
        : func_(func)
        , thread_id_(count++) {
}

Thread::~Thread() {
}

void Thread::start() {
    std::thread t(func_, thread_id_);
    // 分离线程，thread_work 真正的线程可以保留知道线程池析构
    t.detach();
}

int Thread::get_id() {
    return thread_id_;
}