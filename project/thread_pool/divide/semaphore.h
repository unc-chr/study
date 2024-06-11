/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：semaphore.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <atomic>
#include <mutex>
#include <condition_variable>

// 信号量，类似 C++20 支持的信号量
class Semaphore {
public:
    // 构造函数，支持指定默认资源计数
    Semaphore(int limit = 0) : res_limit_(limit), is_exit_(false) {}
    ~Semaphore() {
        is_exit_ = true;
    }
    // 获取一个信号量资源
    void wait() {
        if (is_exit_) {
            return;
        }
        std::unique_lock<std::mutex> lock(mtx_);
        // 等待信号量有资源，没有资源的话，会阻塞当前线程
        cond_.wait(lock, [&]()->bool {return res_limit_ > 0;});
        res_limit_--;
    }
    // 增加一个信号量资源
    void post() {
        if (is_exit_) {
            return;
        }
        std::unique_lock<std::mutex> lock(mtx_);
        res_limit_++;
        cond_.notify_all();
    }
private:
    // 资源计数
    int res_limit_;
    // 判断信号量是否析构，如果析构，wait 和 post 就无意义了。
    std::atomic_bool is_exit_;
    std::mutex mtx_;
    std::condition_variable cond_;
};