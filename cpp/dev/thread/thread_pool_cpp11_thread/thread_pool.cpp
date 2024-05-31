/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：thread_pool.cpp
*   Author：leekaihua
*   Date：2024年04月01日
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
using std::vector;

namespace lee {
    namespace utility {
        class ThreadPool {
            private:
                int m_thread_capacity;
                queue<function<void()>> q_task;
                vector<thread> threads;
                bool m_stop;
            private:
                mutex mtx;
                condition_variable cv;
            public:
                ThreadPool(int thread_capacity = 4, bool stop = false) 
                        : m_thread_capacity(thread_capacity), m_stop(stop) {
                    for (int i = 0; i < m_thread_capacity; i++) {
                        threads.emplace_back([this] {
                            while (true) {
                                std::unique_lock<mutex> lock(mtx);
                                cv.wait(lock, [this] {
                                    return !q_task.empty() || m_stop;
                                });
                                if (q_task.empty() && m_stop) {
                                    return;
                                }
                                function<void()> task(std::move(q_task.front()));
                                q_task.pop();
                                lock.unlock();
                                task();
                            }
                        });
                    }
                }

                ~ThreadPool() {
                    {
                        std::unique_lock<mutex> lock(mtx);
                        m_stop = true;
                    }
                    cv.notify_all();
                    for (auto& t : threads) {
                        t.join();
                    }
                }

            public:
                template <typename F, typename... Args>
                void commit(F&& f, Args... args) {
                    function<void()> task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
                    {
                        std::unique_lock<mutex> lock(mtx);
                        q_task.emplace(std::move(task));
                    }
                    cv.notify_all();
                }
        };
    }
}

int main() {
    lee::utility::ThreadPool tp(4);
    for (int i = 0; i < 20; i++) {
        tp.commit([i] {
            cout << "this is " << i << " thread start." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "this is " << i << " thread end." << endl;
        });
    }
    return 0;
}
