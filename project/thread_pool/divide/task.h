/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：task.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#ifndef __TASK_H
#define __TASK_H

#include "any.h"
#include "result.h"

class Result;

// 线程执行的任务抽象基类
// 用户可以自定义任意任务类型，从 Task 继承，重写 run 方法
class Task {
public:
    Task();
    ~Task() = default;
    void exec();
    void set_result(Result* res);

    // 作为工作线程的回调函数
    virtual Any run() = 0;
private:
    // Result 对象的生命周期长于 Task
    Result* result_;
};

#endif