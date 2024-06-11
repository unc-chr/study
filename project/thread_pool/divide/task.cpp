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

//////////////////// Task 方法的实现
Task::Task() : result_(nullptr) {}

void Task::exec() {
    // 这里执行 run 函数时发生多态 
    if (result_ != nullptr) {
        result_->set_value(run());
    }
}

void Task::set_result(Result* res) {
    result_ = res;
}