/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：shared_ptr.h
*   Author：leekaihua
*   Date：20240603
*   Brife：
*       实现共享智能指针
*/

#pragma once

namespace lee {
namespace util {
template <typename T>
class SharedPtr {
    template<typename Y> friend class Weakptr;
    public:
        SharedPtr() : data_(nullptr), count_(nullptr) {}
        SharedPtr(T* data) : data_(data) {
            if (data != nullptr) {
                count_ = new int(1);
            }
        }
        SharedPtr(const SharedPtr<T>& other) 
                : data_(other.data_)
                , count_(other.count_) {
            if (data_ != nullptr) {
                // 引用计数+1
                (*count_)++;
            }
        }
        SharedPtr(SharedPtr<T>&& other) noexcept 
                : data_(other.data_)
                , count_(other.count_) {
            other.data_ = nullptr;
            other.count_ = nullptr;
        }
        ~SharedPtr() {
            if (data_ != nullptr) {
                (*count_)--;
                if (*count_ <= 0) {
                    delete data_;
                    data_ = nullptr;
                    delete count_;
                    count_ = nullptr;
                }
            }
        }
        T* get() const {
            return data_;
        }
        void reset(T* data = nullptr) {
            if (data_ == data) {
                return;
            }
            if (data_ == nullptr) {
                if (data != nullptr) {
                    data_ = data;
                    count_ = new int(1);
                }
                return;
            }
            (*count_)--;
            if (*count_ <= 0) {
                delete data_;
                data_ = nullptr;
                delete count_;
                count_ = nullptr;
            }
            data_ = data;
            if (data != nullptr) {
                count_ = new int(1);
            }
        }
        int use_count() const {
            if (data_ == nullptr) {
                return 0;
            }
            return *count_;
        }
        bool unique() const {
            if (data_ == nullptr) {
                return false;
            }
            return *count_ == 1;
        }
        void swap(SharedPtr<T>& other) {
            auto data = other.data_;
            auto count = other.count_;
            other.data_ = data_;
            other.count_ = count_;
            data_ = data;
            count_ = count;
        }
        T* operator->() const {
            return data_;
        }
        T& operator*() const {
            return *data_;
        }
        explicit operator bool() const noexcept {
            return data_ != nullptr;
        }
        SharedPtr& operator=(const SharedPtr<T>& other) {
            if (this == &other) {
                return *this;
            }
            data_ = other.data_;
            count_ = other.count_;
            (*count_)++;
            return *this;
        }
        SharedPtr& operator=(SharedPtr<T>&& other) noexcept {
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