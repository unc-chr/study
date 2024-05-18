/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_thread_pool.cpp
*   Author：leekaihua
*   Date：2024年03月30日
*   Brife：
*



*/
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using std::condition_variable;
using std::cout;
using std::endl;
using std::function;
using std::mutex;
using std::queue;
using std::thread;
using std::unique_lock;
using std::vector;

class ThreadPool {
    private:
        vector<thread> threads;  // 线程数组，或理解为线程队列
        queue<function<void()>>  q_tasks;  // 任务队列

        mutex mtx;  // 互斥锁，防止线程竞争
        condition_variable cv;  // 条件变量，通知消费者消费

        bool stop;  // 线程停止标志
    public:
        ThreadPool(int num_threads) : stop(false) {
            for (int i = 0; i < num_threads; i++) {
                threads.emplace_back([this] {
                    while (true) {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this] {
                            return !q_tasks.empty() || stop;
                        });

                        if (stop && q_tasks.empty()) {
                            return;
                        }
                        function<void()> task(std::move(q_tasks.front()));
                        q_tasks.pop();
                        lock.unlock();
                        task();
                    }
                });
            }
        }

        ~ThreadPool() {
            {
                unique_lock<mutex> lock(mtx);
                stop = true;
            }
            cv.notify_all();
            for (auto &t : threads) {
                t.join();
            }
        }

        template <typename F, typename... Args>
        void enqueue(F&& f, Args&&... args) {
            function<void()> task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
            {
                unique_lock<mutex> lock(mtx);
                q_tasks.emplace(std::move(task));
            }
            cv.notify_one();
        }
};

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 10; i++) {
        pool.enqueue([i] {
            cout << "task: " << i << " begin running..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "task: " << i << " done!" << endl;
        });
    }
    return 0;
}