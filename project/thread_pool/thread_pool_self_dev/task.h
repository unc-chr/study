/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：task.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include "any.h"
#include "result.h"

// 前向声明
class Result;
class Task {
public:
    Task();
    virtual ~Task() = default;

    // 派生类进行具体的实现
    virtual Any run() = 0;

    // 返回任务编号
    uint32_t get_task_num();

    // task 的执行函数，内部调用 SubTask 的 run 函数。
    // 函数的执行结果，存储到任务反馈中。
    void exec();

    // 设置任务的反馈结果，也就是 task 和 result 关联起来
    // 每个任务都有一个反馈
    void set_result(Result* result);

private:
    static uint32_t count_;
    uint32_t number_;
    // 持有 result 对象，目的是将 task 的执行结果存储到 result 中。
    // 不用 shared_ptr，目的是防止循环引用。因此也能使用 weak_ptr。
    Result* result_;
};
