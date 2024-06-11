/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：result.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
        提交任务的反馈
        其中包含任务执行的结果，并提供阻塞机制，依靠信号量实现
*/

#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "any.h"
#include "semaphore.h"
#include "task.h"

// 前向声明
class Task;
class Result {
public:
    // 默认构造函数
    Result() = default;
    // 使用任务进行构造
    Result(std::shared_ptr<Task> task, const std::string& info);
    Result(const Result&) = delete;
    Result& operator=(const Result&) = delete;
    Result(Result&&) = default;
    Result& operator=(Result&&) = default;

    // 析构
    ~Result() = default;

    void get_info();
    void set_info(const std::string& info);
    void set_res(Any&&);
    Any get_res();

private:
    // 当前反馈关联的任务，每个任务提交之后都有一个反馈。
    std::shared_ptr<Task> task_;
    // 反馈信息
    std::string info_;
    // 关联任务的执行结果
    Any any_;
    // 信号量
    Semaphore sem_;
};