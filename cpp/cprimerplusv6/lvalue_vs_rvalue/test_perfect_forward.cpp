/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_perferct_forward.cpp
*   Author：leekaihua
*   Date：20240605
*   Brife：
*



*/

#include <iostream>
#include <string>

template <typename T>
void show_type(T t) {
    std::cout << typeid(t).name() << std::endl;
}

// normal forward, get T type var, and show its typename
template <typename T>
void normal_forwarding(T t) {
    show_type(t);
}

// normal forward, get T type var with lvalue ref, 
// and show its typename
template <typename T>
void normal_forwarding_lref(T& t) {
    show_type(t);
}

// perfect forward, use univeral reference
template <typename T>
void perfect_forwarding(T&& t) {
    show_type(static_cast<T&&>(t));
}

std::string get_str() {
    return "hello world";
}

int main() {
    std::string s = "hello world";
    normal_forwarding(s);
    normal_forwarding(1);
    double a = 0.5;
    normal_forwarding(a);
    // can't bind a no-const lvalue ref to rvalue
    // compile error
    // normal_forwarding_lref(get_str());
    perfect_forwarding(get_str());
    return 0;
}