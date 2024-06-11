/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：any.h
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#pragma once

#include <memory>

// Any 类型：可以接收任意数据的类型
class Any {
    private:
        // 基类类型
        class Base {
            public:
                virtual ~Base() = default;
        };
        // 派生类类型
        template<typename T>
        class Derive : public Base {
            public:
                T data_;
                Derive(T data) : data_(data) {}
        };
    private:
        // 定义一个基类的指针
        std::unique_ptr<Base> base_;
    public:
        Any() = default;
        ~Any() = default;
        Any(const Any&) = delete;
        Any& operator=(const Any&) = delete;
        Any(Any&&) = default;
        Any& operator=(Any&&) = default;

        // 该构造函数允许 Any 类型接受其他任意类型的数据
        template<typename T>
        Any(T data) : base_(std::make_unique<Derive<T>>(data)) {}
        // Any(T data) : base_(new Derive<T>(data)) {}

        // 将 Any 对象中存储的其他类型的对象提取出来。
        template<typename T>
        T cast_() {
            // 从 base_ 中找到它所指向的 Derive 对象，从里面取出 data 成员变量
            // 基类指针 =》 派生类指针
            Derive<T>* pd = dynamic_cast<Derive<T>*>(base_.get());
            if (pd == nullptr) {
                throw "type is incompatiable!";
            }
            return pd->data_;
        }
};
