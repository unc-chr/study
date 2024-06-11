/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_main.cpp
*   Author：leekaihua
*   Date：20240610
*   Brife：
*



*/
#include <memory>

#include "result.h"
#include "thread_pool.h"
#include "sub_task.h"

int main() {
#if 0
    {
        ThreadPool pool;
        pool.start();
        pool.set_thread_pool_mode(THREAD_MODE::MODE_FIXED);

        std::shared_ptr<SubTask> task1 = std::make_shared<SubTask>(1, 2);
        Result res1 = pool.submit_task(task1);
        std::shared_ptr<SubTask> task2 = std::make_shared<SubTask>(2, 3);
        Result res2 = pool.submit_task(task2);
        std::shared_ptr<SubTask> task3 = std::make_shared<SubTask>(3, 4);
        Result res3 = pool.submit_task(task3);
        std::shared_ptr<SubTask> task4 = std::make_shared<SubTask>(4, 5);
        Result res4 = pool.submit_task(task4);
        
        std::cout << "main" << std::endl;
        double real_res1 = res1.get_res().any_cast<double>();
        std::cout << "main" << real_res1 << std::endl;
        double real_res2 = res2.get_res().any_cast<double>();
        std::cout << "main" << real_res2 << std::endl;
        double real_res3 = res3.get_res().any_cast<double>();
        std::cout << "main" << real_res3 << std::endl;
        double real_res4 = res4.get_res().any_cast<double>();
        std::cout << "main" << real_res4 << std::endl;

        // std::this_thread::sleep_for(std::chrono::seconds(5));
        // 出作用域，pool 和 result 都会析构
    }
#endif
    {
        // 两个线程，任务队列容量设置为4，理论上超过6个任务就会被提示提交失败。
        ThreadPool pool;
        pool.start(2);
        pool.set_thread_pool_mode(THREAD_MODE::MODE_FIXED);

        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(1, 2));
    }
    return 0;
}