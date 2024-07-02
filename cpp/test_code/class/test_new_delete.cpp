/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_new.cpp
*   Author：leekaihua
*   Date：20240624
*   Brife：
*



*/
#include <iostream>
#include <new>

void* operator new(size_t size) {
    void* p = malloc(size);
    if (p == nullptr) {
        throw std::bad_alloc();
    }
    std::cout << "operator new addr: " << p << std::endl;
    return p;
}

void operator delete(void* ptr) {
    std::cout << "operator delete addr: " << ptr << std::endl;
    free(ptr);
}

void* operator new[](size_t size) {
    void* p = malloc(size);
    if (p == nullptr) {
        throw std::bad_alloc();
    }
    std::cout << "operator new[] addr: " << p << std::endl;
    return p;
}

void operator delete[](void* ptr) {
    std::cout << "operator delete[] addr: " << ptr << std::endl;
    free(ptr);
}

class Test {
public:
    Test() {
        std::cout << "Test() this addr: " << this << std::endl;
    }
    ~Test() {
        std::cout << "~Test() this addr: " << this << std::endl;
    }
private:
    int data;
};

int main() {
#if 0
    try {
        int* p = new int(1);
        delete[] p;

        int* q = new int[10];
        delete q;
    } catch (const std::bad_alloc& err) {
        std::cerr << err.what() << std::endl;
    }
#endif
    // Test* p1 = new Test();
    // delete[] p1;

    // output as following
    // Test()
    // Test()
    // Test()
    // Test()
    // Test()
    // ~Test()
    // operator delete addr: 0xa5f018
    // Segmentation fault (core dumped)
    Test* p2 = new Test();
    delete p2;

    return 0;
}