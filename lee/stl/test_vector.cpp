/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_vector.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#if 0
using std::vector;
#endif

#if 1
#include "vector.h"
using lee::stl::vector;
#endif

using std::cout;
using std::endl;

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2(v);
    vector<int> v3;
    v3 = v;
    assert(v.size() == 4);
    assert(!v.empty());
    assert(v.full());
    assert(v.front() == 0);
    assert(v.back() == 3);
    assert(v[2] = 2);
    assert(v.at(2) = 2);
    v.pop_back();
    assert(v.size() == 3);
    assert(v.back() == 2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // vector<int> v = {8, 4, 5, 9};
    // v[2] = -1;
    // for (int n : v) {
    //     cout << n << " ";
    // }
    cout << endl;

    return 0;
}
