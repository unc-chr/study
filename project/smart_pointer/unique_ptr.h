/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：unique_ptr.h
*   Author：leekaihua
*   Date：20240603
*   Brife：
*       自己实现以下 unique_ptr 智能指针
*/

#pragma once

namespace lee {
namespace util {
    template <typename T>
    class UniquePtr {
    public:
        UniquePtr() : data_(nullptr) {}
        UniquePtr(T* data) : data_(data) {}
        // 禁用拷贝构造函数
        UniquePtr(const UniquePtr& other) = delete;
        UniquePtr(UniquePtr<T>&& other) : data_(other.release()) {};
        // 禁用赋值构造函数
        UniquePtr& operator=(const UniquePtr<T>& other) = delete;
        UniquePtr& operator=(UniquePtr<T>&& other) {
            if (this == &other) {
                return *this;
            }
            reset(other.release());
            return *this;
        }
        ~UniquePtr() {
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
        T& operator[](int i) const {
            return data_[i];
        }
        explicit operator bool() const noexcept {
            return data_ != nullptr;
        }

        // 返回原始的指针
        T* get() {
            return data_;
        }
        // 释放指针的所有权
        T* release() {
            T* data = data_;
            data_ = nullptr;
            return data;
        }
        // 重置
        void reset(T* data = nullptr) {
            if (data_ != data) {
                delete data_;
                data_ = data;
            }
        }
        // 内部指针交换
        void swap(UniquePtr<T>& other) {
            auto data = other.data_;
            other.data_ = data_;
            data_ = data;
        }
    private:
        T* data_;
    };
}
}