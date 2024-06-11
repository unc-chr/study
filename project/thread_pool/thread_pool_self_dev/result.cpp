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

Result::Result(std::shared_ptr<Task> task, const std::string& info)
        : task_(task)
        , info_(info) {
    task_->set_result(this);
}

// 查看反馈信息
void Result::get_info() {
    std::cout << info_ << std::endl;
}

// 存储反馈信息
void Result::set_info(const std::string& info) {
    info_ = info;
}

// 存储任务结果
void Result::set_res(Any&& any) {
    any_ = std::move(any);
    sem_.post();
    set_info("task done!");
}

//  获取任务结果
Any Result::get_res() {
    sem_.wait();
    return std::move(any_);
}