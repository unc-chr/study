/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：result.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include "result.h"

//////////////////// Result 方法的实现
Result::Result(std::shared_ptr<Task> task, bool is_vaild) 
        : is_vaild_(is_vaild)
        , task_(task) {
    task_->set_result(this);
}

Any Result::get() {
    if (!is_vaild_) {
        return "";
    }

    // task 任务如果没有执行完，这里会阻塞用户的线程
    sem_.wait();
    return std::move(any_);
}

void Result::set_value(Any any) {
    // 存储 task 的返回值
    this->any_ = std::move(any);
    // 已经获取了任务的返回值，增加信号量资源
    sem_.post();
}