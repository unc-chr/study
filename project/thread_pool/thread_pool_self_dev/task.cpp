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
}

uint32_t Task::get_task_num() {
    return number_;
}

void Task::exec() {
    Any temp = run();
    result_->set_res(std::move(temp));
}

void Task::set_result(Result* result) {
    result_ = result;
}