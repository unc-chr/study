/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_async_promise.cpp
*   Author：leekaihua
*   Date：2024年04月01日
*   Brife：
*



*/
#include <future>
#include <iostream>

void func(std::promise<int>& f) {
    f.set_value(1000);
}

int main() {
    std::promise<int> f;
    auto future_result = f.get_future();

    std::thread t1(func, std::ref(f));

    t1.join();

    std::cout << future_result.get() << std::endl;

    return 0;
}