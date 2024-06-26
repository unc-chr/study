/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：pairs.h
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#pragma once
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
    private:
        T1 a;
        T2 b;
    public:
        Pair() {}
        Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
        T1& first();
        T2& second();
        T1 first() const {return a;}
        T2 second() const {return b;}
};

template <typename T1, typename T2>
T1& Pair<T1, T2>::first() {
    return a;
}

template <typename T1, typename T2>
T2& Pair<T1, T2>::second() {
    return b;
}