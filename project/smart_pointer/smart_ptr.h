/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：smart_ptr.h
*   Author：leekaihua
*   Date：20240602
*   Brife：
*



*/
#pragma once

namespace lee {
namespace util {
    template <typename T>
    class SmartPtr {
    public:
        SmartPtr() : data_(nullptr) {}
        SmartPtr(T* data) : data_(data) {}
        ~SmartPtr() {
            if (data_ != nullptr) {
                delete data_;
                data_ = nullptr;
            }
        }

        T* operator->() {
            return data_;
        }
        T& operator*() {
            return *data_;
        }
    private:
        T* data_;
    };
}
}