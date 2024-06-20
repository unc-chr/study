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
#if 1
    {
        ThreadPool pool;
        // pool.set_thread_pool_mode(ThreadPoolMode::MODE_FIXED);
        pool.set_thread_pool_mode(ThreadPoolMode::MODE_CACHED);
        pool.set_task_queue_max_thresh_hold(4);
        pool.set_thread_workers_max_size(10);
        pool.start(2);

        std::shared_ptr<SubTask> task1 = std::make_shared<SubTask>(1, 2);
        Result res1 = pool.submit_task(task1);
        std::shared_ptr<SubTask> task2 = std::make_shared<SubTask>(2, 3);
        Result res2 = pool.submit_task(task2);
        std::shared_ptr<SubTask> task3 = std::make_shared<SubTask>(3, 4);
        Result res3 = pool.submit_task(task3);
        std::shared_ptr<SubTask> task4 = std::make_shared<SubTask>(4, 5);
        Result res4 = pool.submit_task(task4);
        std::shared_ptr<SubTask> task5 = std::make_shared<SubTask>(1, 2);
        Result res5 = pool.submit_task(task5);
        std::shared_ptr<SubTask> task6 = std::make_shared<SubTask>(2, 3);
        Result res6 = pool.submit_task(task6);
        std::shared_ptr<SubTask> task7 = std::make_shared<SubTask>(3, 4);
        Result res7 = pool.submit_task(task7);
        std::shared_ptr<SubTask> task8 = std::make_shared<SubTask>(4, 5);
        Result res8 = pool.submit_task(task8);
        
        std::cout << "main" << std::endl;
        double real_res1 = res1.get_res().any_cast<double>();
        std::cout << "main" << real_res1 << std::endl;
        // double real_res2 = res2.get_res().any_cast<double>();
        // std::cout << "main" << real_res2 << std::endl;
        // double real_res3 = res3.get_res().any_cast<double>();
        // std::cout << "main" << real_res3 << std::endl;
        // double real_res4 = res4.get_res().any_cast<double>();
        // std::cout << "main" << real_res4 << std::endl;

        // std::this_thread::sleep_for(std::chrono::seconds(5));
        // 出作用域，pool 和 result 都会析构
    }
#endif
#if 0
    {
        // 两个线程，任务队列容量设置为4，理论上超过6个任务就会被提示提交失败。
        ThreadPool pool;
        pool.set_thread_pool_mode(ThreadPoolMode::MODE_CACHED);
        pool.set_task_queue_max_thresh_hold(4);
        pool.start(2);

        pool.submit_task(std::make_shared<SubTask>(1, 2));
        pool.submit_task(std::make_shared<SubTask>(2, 2));
        pool.submit_task(std::make_shared<SubTask>(3, 2));
        pool.submit_task(std::make_shared<SubTask>(4, 2));
        pool.submit_task(std::make_shared<SubTask>(5, 2));
        pool.submit_task(std::make_shared<SubTask>(6, 2));
        pool.submit_task(std::make_shared<SubTask>(7, 2));
        pool.submit_task(std::make_shared<SubTask>(8, 2));
    }
#endif
    return 0;
}