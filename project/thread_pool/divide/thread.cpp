/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include "thread.h"

//////////////// 线程方法实现 ////////////////

int Thread::generate_id_ = 0;

Thread::Thread(ThreadFunc func)
        : func_(func)
        , thread_id_(generate_id_++) {

}

Thread::~Thread() {

}

void Thread::start() {
    // 创建一个线程来执行一个线程函数
    // 线程对象是t，线程函数是 func, func 是真正的线程。
    std::thread t(func_, thread_id_);

    // 设置分离线程
    // t 本身是个局部变量，出作用域之后会析构，设置分离后，真正的线程（线程函数）可以存活。
    // 线程函数会等待任务到来并执行，其实际存在于线程容器中。
    t.detach();    
}

int Thread::get_id() const {
    return thread_id_;
}