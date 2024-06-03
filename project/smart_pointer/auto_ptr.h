/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：auto_ptr.h
*   Author：leekaihua
*   Date：20240603
*   Brife：
*       参照官网的 api 和介绍，自己实现一下 auto_ptr。



*/
#pragma once

namespace lee {
namespace util {
    template <typename T>
    class AutoPtr {
    public:
        AutoPtr() : data_(nullptr) {}
        AutoPtr(T* data) : data_(data) {}
        // 使用已经存在的 autoptr 初始化
        AutoPtr(AutoPtr& other) : data_(other.release()) {};
        AutoPtr& operator=(AutoPtr<T>& other) {
            if (this == &other) {
                return *this;
            }
            data_ = other.release();
            return *this;
        }
        ~AutoPtr() {
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
    private:
        T* data_;
    };
}
}