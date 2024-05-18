/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_errors.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class MyClass {
    public:
        void func() {
            cout << "Thread " << std::this_thread::get_id() << " started." << endl;
            // do some work
            cout << "Thread " << std::this_thread::get_id() << " finished." << endl;
        }
};

thread t1;

void foo(int& x) {
    x += 1;
}

void foo1(int* x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    *x += 1;
    cout << *x << endl;
}

void test() {
    int b = 1;
    t1 = thread(foo, std::ref(b));
}

int main() {
    int a = 1;
    thread t(foo, std::ref(a));
    test();

    int* ptr = new int(3);
    thread t2(foo1, ptr);
    delete ptr;

    MyClass obj;
    thread t3(&MyClass::func, &obj);

    t.join();
    t1.join();
    t2.join();
    t3.join();
    cout << "a: " << a << endl;
    return 0;
}