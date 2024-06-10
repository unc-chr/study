/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：any.h
*   Author：leekaihua
*   Date：20240610
*   Brife：
*       implement a any class use C++11.
        Even though this is supported since C++17 and in boost lib.

*/

#pragma once

#include <memory>

class Any {
public:
    Any() = default;
    ~Any() = default;
    Any(const Any&) = delete;
    Any(Any&&) = default;
    Any& operator=(Any&) = delete;
    Any& operator=(Any&&) = default;

    template<typename T>
    Any(T data) : base_(std::make_unique<Derive<T>>(data)) {}

    template<typename T>
    T any_cast() {
        Derive<T>* pd = dynamic_cast<Derive<T>*>(base_.get());
        if (pd == nullptr) {
            throw "type is incompatiable!";
        }
        return pd->data_;
    }
private:
    // Base class
    // Any class want Base pointer to call Derive instance
    class Base {
    public:
        // Base class deconstructor should be virtual
        virtual ~Base() = default;
    };

    // Derive class
    template<typename T>
    class Derive : public Base {
    public:
        Derive(T data) : data_(data) {}
        virtual ~Derive() = default;
    public:
        T data_;
    };

    // Base*, keep a pointer to call Derive instance
    std::unique_ptr<Base> base_;
};