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
#include <condition_variable>
#include <mutex>

// 基于互斥锁和条件变量的信号量
// 信号量的初始值是0.
class Semaphore {
public:
    Semaphore(int signal = 0) : signal_(signal), is_exit_(false) {}
    ~Semaphore() {
        is_exit_ = true;
    }
    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;
    Semaphore(Semaphore&&) = default;
    Semaphore& operator=(Semaphore&&) = default;

    // 将信号量的值减1，相当于加锁。信号量小于等于0，那么线程将阻塞
    // 初始值是0，所以如果先执行wait，会阻塞。
    void wait() {
        if (is_exit_) {
            return;
        }
        {
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [this]()->bool {return signal_ > 0;});
            signal_--;
        }
    }

    // 将信号量的值加1，相当于解锁。信号量大于0，那么线程可以执行
    // 初始值是0，所以必须先 post，才能 wait。
    void post() {
        if (is_exit_) {
            return;
        }
        {
            std::unique_lock<std::mutex> lock(mtx_);
            signal_++;
        }
        cv_.notify_all();
    }
private:
    int signal_;
    std::atomic_bool is_exit_;
    std::mutex mtx_;
    std::condition_variable cv_;
};