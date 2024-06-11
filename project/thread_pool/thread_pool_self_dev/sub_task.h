/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：sub_task.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <chrono>
#include <iostream>
#include <thread>

#include "task.h"

class SubTask : public Task {
public:
    SubTask(double arg1, double arg2)
            : arg1_(arg1)
            , arg2_(arg2) {}
    virtual ~SubTask() = default;

    virtual Any run() {
        double res = arg1_ + arg2_;
        std::cout << arg1_ << " + " << arg2_ << " = " << res << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "job " << Task::get_task_num() << " done." << std::endl;
        return res;
    }

private:
    double arg1_;
    double arg2_;
};