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

#include <condition_variable>
#include <mutex>

// 基于互斥锁和条件变量的信号量
class Semaphore {
public:
    Semaphore() : signal_(1) {}
    ~Semaphore() = default;
    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;
    Semaphore(Semaphore&&) = default;
    Semaphore& operator=(Semaphore&&) = default;

    // 将信号量的值减1，相当于加锁
    // 信号量小于等于0，那么线程将阻塞
    void wait() {
        {
            std::unique_lock<std::mutex> lock(mtx_);
            while (signal_ <= 0) {
                cv_.wait(lock);
            }
            signal_--;
        }
    }

    // 将信号量的值加1，相当于解锁
    // 信号量大于0，那么线程可以执行
    void post() {
        {
            std::unique_lock<std::mutex> lock(mtx_);
            signal_++;
        }
    }
private:
    int signal_;
    std::mutex mtx_;
    std::condition_variable cv_;
};