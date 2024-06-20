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

Result::Result(std::shared_ptr<Task> task, const std::string& info, bool is_valid)
        : task_(task)
        , info_(info)
        , is_valid_(is_valid)
        , is_exit_(true) {
    task_->set_result(this);
}

Result::~Result() {
    is_exit_ = false;
    std::cout << "result destroy!" << std::endl;
}

// 查看反馈信息
void Result::get_info() {
    if (!is_exit_) {
        return;
    }
    std::cout << info_ << std::endl;
}

// 存储反馈信息
void Result::set_info(const std::string& info) {
    if (!is_exit_) {
        return;
    }
    info_ = info;
}

// 存储任务结果
void Result::set_res(Any any) {
    if (!is_exit_) {
        return;
    }
    this->any_ = std::move(any);
    sem_.post();
    set_info("task done!");
}

//  获取任务结果
Any Result::get_res() {
    // 如果任务提交失败，is_valid_ 为 false，那么无法获取任务
    if (!is_valid_) {
        return "";
    }
    if (!is_exit_) {
        return "";
    }
    sem_.wait();
    return std::move(any_);
}