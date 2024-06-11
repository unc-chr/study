/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：result.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#ifndef __RESULT_H
#define __RESULT_H

#include <atomic>

#include "any.h"
#include "semaphore.h"
#include "task.h"

// Task 类型的前置声明
class Task;
// Result: 任务提交到线程池，执行完毕之后的返回值类型
class Result {
public:
    Result(std::shared_ptr<Task> task, bool is_vaild = true);
    ~Result() = default;

    // set value 方法，获取任务执行完的返回值
    void set_value(Any any);

    // get 方法，用户调用该方法获取 task 的返回值
    Any get();

private:
    // 存储任务的返回值
    Any any_;  

    // 线程通信信号量
    Semaphore sem_;

    // 返回值是否有效
    std::atomic_bool is_vaild_;

    // 指向要获取返回值的任务对象
    std::shared_ptr<Task> task_;
};

#endif