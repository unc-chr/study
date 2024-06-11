/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <functional>
#include <thread>

// 线程类型
class Thread {
    public:
        // 线程函数对象类型
        using ThreadFunc = std::function<void(int)>;
        // 构造函数
        Thread(ThreadFunc func);
        // 析构函数
        ~Thread();
        // 启动线程，线程会执行一个函数
        void start();

        // 获取线程id
        int get_id() const;
    private:
        static int generate_id_;
        ThreadFunc func_;
        // 保存线程id
        int thread_id_;
};