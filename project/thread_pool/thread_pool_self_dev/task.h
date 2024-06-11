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

#include <iostream>

#include "any.h"
#include "result.h"

// 前向声明
class Result;
class Task {
public:
    Task();
    // 派生类进行具体的实现
    virtual Any run() = 0;

    // 返回任务编号
    uint32_t get_task_num();

    // 实际的执行函数，是 subtask 的 run 函数
    // 函数的执行结果，存储到任务反馈中。
    void exec();

    // 设置 Result 对象，和 Result 关联起来
    void set_result(Result* result);

private:
    static uint32_t count_;
    uint32_t number_;
    // 持有 result 对象，目的是将 task 的执行结果存储到 result 中。
    // 不用 shared_ptr，目的是防止循环引用。因此也能使用 weak_ptr。
    Result* result_;
};