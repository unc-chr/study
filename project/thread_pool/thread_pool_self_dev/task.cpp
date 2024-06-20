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
    // task/subtask 的创建先于 result，应该设置为 nullptr
    // submit_task 函数返回的时候，再由 set_result 设置具体值。
    result_ = nullptr;
}

uint32_t Task::get_task_num() {
    return number_;
}

void Task::exec() {
    // if 判断，防止还未将 result 和 task 关联起来的时候，
    // 就调用任务执行了。
    if (result_ != nullptr) {
        result_->set_res(run());
    }
}

void Task::set_result(Result* result) {
    result_ = result;
}
