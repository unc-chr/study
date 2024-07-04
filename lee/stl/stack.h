/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：stack.h
*   Author：mayi
*   Date：20240704
*   Brife：
*
    implement stack container using container adapter feature.
    stack is based on deque container.
    so 
        step1: implement stack with std::deque.
        step2: implement stack with lee::stl::deque. 
*/

#pragma once

#include <deque>
using std::deque;

namespace lee {
namespace stl {

template <typename T, typename Container = deque<T>>
class stack {
public:
    void push(T item);
    void pop();
    T top();
    bool empty() const;
    size_t size() const;
private:
    Container _con;
};

}
}

namespace lee {
namespace stl {

template <typename T, typename Container>
void stack<T, Container>::push(T item) {
    _con.push_back(item);
}

template <typename T, typename Container>
void stack<T, Container>::pop() {
    _con.pop_back();
}

template <typename T, typename Container>
T stack<T, Container>::top() {
    return _con.back();
}

template <typename T, typename Container>
bool stack<T, Container>::empty() const {
    return _con.empty();
}

template <typename T, typename Container>
size_t stack<T, Container>::size() const {
    return _con.size();
}

}
}