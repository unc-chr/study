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

    BigMemoryPool& operator=(const BigMemoryPool& other) {
        if (this == &other) {
            return *this;
        }
        std::cout << "assignment big memory pool." << std::endl;
        delete [] pool_;
        pool_ = other.pool_;
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
    BigMemoryPool my_pool = make_pool();
    return 0;
}