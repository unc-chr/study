/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：task.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include "task.h"

uint32_t Task::count_ = 0;

Task::Task() {
    count_++;
    number_ = count_;
    result_ = nullptr;
}

uint32_t Task::get_task_num() {
    return number_;
}

void Task::exec() {
    if (result_ != nullptr) {
        result_->set_res(run());
    }
}

void Task::set_result(Result* result) {
    result_ = result;
}