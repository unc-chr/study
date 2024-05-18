/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2024年03月29日
*   Brife：
*



*/

#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class MyClass {
    friend void thread_foo();
    private:
        void foo() {
            cout << "hello" << endl;
        }
};

void thread_foo() {
    std::shared_ptr<MyClass> obj = std::make_shared<MyClass>();
    std::thread t(&MyClass::foo, obj);
    t.join();
}

// int main() {
//     thread_foo();
//     return 0;
// }


int loop(int n) {
    static int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

int main() {
    int res1 = 0;
    int res2 = 0;
    res1 = loop(10);
    res2 = loop(13);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}