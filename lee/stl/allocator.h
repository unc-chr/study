/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：allocator.h
*   Author：leekaihua
*   Date：20240701
*   Brife：
*
*       容器空间配置器
*/

#pragma once

namespace lee {
namespace stl {

template <typename T>
struct Allocator {
    T* allocate(size_t size) {
        return (T*)malloc(size * sizeof(T));
    }

    void deallocate(void* p) {
        free(p);
    }

    // 对象构建
    // 使用定位 new 运算符和拷贝构造
    void construct(T* p, const T& other) {
        new(p) T(other);
    }

    // 对象析构
    void destroy(T* p) {
        p->~T();
    }
};

}
}