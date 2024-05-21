/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：noncopy.h
*   Author：leekaihua
*   Date：2024年03月27日
*   Brife：
*



*/
#pragma once

class NoneCopy {
    public:
        ~NoneCopy() {}
    protected:
        NoneCopy() {}
    private:
        NoneCopy(const NoneCopy&) = delete;
        NoneCopy& operator=(const NoneCopy&) = delete;
};

// 单例模式
class ThreadPool : public NoneCopy {
    public:
        ~ThreadPool();
        static ThreadPool& instance() {
            static ThreadPool ins;
            return ins;
        }
    private:
        ThreadPool();
};