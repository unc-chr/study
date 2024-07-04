/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_stack.cpp
*   Author：mayi
*   Date：20240704
*   Brife：
*



*/

#include <cassert>

#if 0
#include <stack>
using std::stack;
#endif

#if 1
#include "stack.h"
using lee::stl::stack;
#endif

int main() {
    // test constructor
    stack<int> s;
    // test push
    s.push(0);
    s.push(1);
    s.push(2);
    // test size()
    assert(s.size() == 3);
    // test empty()
    assert(!s.empty());
    // test top()
    if (!s.empty()) {
        int item = s.top();
        assert(item == 2);
    }
    // test pop
    assert(s.size() == 3);
    s.pop();
    assert(s.size() == 2);
    s.pop();
    s.pop();
    assert(s.empty());

    return 0;
}