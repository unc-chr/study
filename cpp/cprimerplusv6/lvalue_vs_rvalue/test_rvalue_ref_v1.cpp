/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_rvalue_ref_bad_case.cpp
*   Author：leekaihua
*   Date：20240605
*   Brife：
*



*/
#include <cstring>
#include <chrono>
#include <iostream>

class BigMemoryPool {
public:
    static const int pool_size = 4096;

    // default construct
    BigMemoryPool() : pool_(new char[pool_size]) {
        std::cout << "allocate memory." << std::endl;
    }

    // destroy construct
    ~BigMemoryPool() {
        if (pool_ != nullptr) {
            std::cout << "release memory." << std::endl;
            delete [] pool_;
        }
    }

    // copy construct with lvalue reference
    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[pool_size]) {
        std::cout << "copy big memory pool." << std::endl;
        memcpy(pool_, other.pool_, pool_size);
    }

    // move copy constructor with rvalue reference
    BigMemoryPool(BigMemoryPool&& other) {
        std::cout << "move big memory pool." << std::endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }

    // copy assignment
    BigMemoryPool& operator=(const BigMemoryPool& other) {
        if (this == &other) {
            return *this;
        }
        std::cout << "copy assignment" << std::endl;
        delete [] pool_;
        memcpy(pool_, other.pool_, pool_size);
        return *this;
    }

    // move assignment
    BigMemoryPool& operator=(BigMemoryPool&& other) {
        std::cout << "move assignment" << std::endl;
        if (this == &other) {
            return *this;
        }
        delete [] pool_;
        pool_ = other.pool_;
        other.pool_ = nullptr;
        return *this;
    }

private:
    char* pool_;
};

BigMemoryPool get_pool(const BigMemoryPool& pool) {
    // return a object will generate a temporary object
    return pool;
}

BigMemoryPool make_pool() {
    // call default construct
    BigMemoryPool pool;

    // return a object will generate a temporary object
    return get_pool(pool);
}

// compile with -fno-elide-constructors option.
int main() {
#if 0
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1; i++) {
        BigMemoryPool my_pool = make_pool();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff  = end - start;
    std::cout << "rum time: " << diff.count() << std::endl;
#endif
    // object my_pool hasn't been created, so call move copy constructor
    BigMemoryPool my_pool = make_pool();
    // call default constructor create my_pool object first
    // then move a temparory object to my_pool by calling
    // move assignment constructor
    BigMemoryPool my_pool;
    my_pool = make_pool();
    return 0;
}