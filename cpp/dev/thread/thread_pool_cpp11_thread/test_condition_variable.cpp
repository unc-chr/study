/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_condition_variable.cpp
*   Author：leekaihua
*   Date：2024年03月30日
*   Brife：
*



*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using std::cout;
using std::endl;
using std::condition_variable;
using std::mutex;
using std::queue;

queue<int> q_tasks;
condition_variable cv;
mutex mtx;

void producer() {
    for (int i = 0; i < 10; i++) {
        // 这里的大括号是为了让互斥锁释放掉
        {
            std::unique_lock<std::mutex> lock(mtx);
            q_tasks.push(i);
            cout << "task " << i << " pushed." << endl;
            // 通知消费者取任务执行
            cv.notify_one();
        }
        // 加个延时，否则任务发布地可能太快了。
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void consumer() {
    while (true) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            // 队列为空，需要等待。判断队列空可以使用函数，或者 lambda 表达式。
            // bool is_empty = q_tasks.empty();
            cv.wait(lock, []() {return !q_tasks.empty();});
            int value = q_tasks.front();
            cout << "task " << value << " execute." << endl;
            q_tasks.pop();
        }
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();

    return 0;
}