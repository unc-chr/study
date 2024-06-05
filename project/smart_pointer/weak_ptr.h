/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：weak_ptr.h
*   Author：leekaihua
*   Date：20240603
*   Brife：
*       自己动手实现 weak_ptr
*/

#pragma once

#include "shared_ptr.h"

namespace lee {
namespace util {
    template <typename T>
    class WeakPtr {
    public:
        WeakPtr() : data_(nullptr), count_(nullptr) {}
        // 为了直接访问 private 成员，需要申明友元类
        WeakPtr(const SharedPtr<T>& sp) : data_(sp.data_), count_(sp.count_) {}
        WeakPtr(const WeakPtr<T>& other) : data_(other.data_), count_(other.count_) {}
        WeakPtr(WeakPtr<T>&& other) {
            data_ = other.data_;
            count_ = other.count_;
            other.data_ = nullptr;
            other.count_ = nullptr;
        }
        ~WeakPtr() {
            data_ = nullptr;
            count_ = nullptr;
        }
        void reset() {
            data_ = nullptr;
            count_ = nullptr;
        }
        bool expired() {
            return !count_ || (*count_) <= 0;
        }
        SharedPtr<T> lock() const {
            if (expired()) {
                return SharedPtr<T>();
            }
            SharedPtr<T> sp;
            sp.data_ = data_;
            sp.count_ = count_;
            if (count_ != nullptr) {
                (*count_)++;
            }
            return sp;
        }
        void swap(WeakPtr<T>& other) {
            auto data = other.data_;
            auto count = other.count_;
            other.data_ = data_;
            other.count_ = count_;
            data_ = data;
            count_ = count;
        }
        int use_count() const {
            if (data_ == nullptr) {
                return 0;
            }
            return *data_;
        }
        WeakPtr& operator=(const SharedPtr<T>& sp) {
            data_ = sp.data_;
            count_ = sp.count_;
            return *this;
        }

        WeakPtr& operator=(const WeakPtr<T>&& sp) {
            if (this == &sp) {
                return *this;
            }
            data_ = sp.data_;
            count_ = sp.count_;
            return *this;
        }
        WeakPtr& operator=(WeakPtr<T>&& other) {
            if (this == &other) {
                return *this;
            }
            data_ = other.data_;
            count_ = other.count_;
            other.data_ = nullptr;
            other.count_ = nullptr;
            return *this;
        }
    private:
        T* data_;
        int* count_;
    };
}
}