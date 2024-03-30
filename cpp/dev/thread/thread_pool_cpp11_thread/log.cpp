/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：singleton.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::thread;

//  懒汉模式实现
class Log {
    public:
        static Log& getInstance() {
            std::call_once(once, init);
            // std::call_once(once, [] { log = new Log(); });
            return *log;
        }    
        static void init() {
            log = new Log();
        }
        void print_log(string msg) {
            cout << msg << endl;
        }
    private:
        Log() {
            cout << "default constructor" << endl;
        }
        Log(const Log&) = delete;
        Log& operator=(const Log&) = delete;    
    private:
        static Log* log;
        static std::once_flag once;
};

Log* Log::log = nullptr;
std::once_flag Log::once;

void print_error() {
    Log::getInstance().print_log("error");
}

int main() {
    thread t1(print_error);
    thread t2(print_error);
    t1.join();
    t2.join();

    return 0;
}