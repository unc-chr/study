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

// if want compile with stl vector, set 1.
#if 0
using std::vector;
#endif

// if want compile with own vector, set 1
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
    // assert(v.full());
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
    // test iterator and erase
    v.erase(v.begin() + 3);
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;

    // test iterator failure with for loop
    vector<int> v1;
    for (int i = 0; i < 20; i++) {
        v1.push_back(rand() % 100);
    }
    cout << "before remove even number: ";
    for (auto iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
#if 0
    // actually, combination of for syntax and erase to delete even number
    // is not good, even though no iterator failure.
    // use while loop is better.
    for (auto iter = v1.begin(); iter != v1.end(); iter++) {
        if (*iter % 2 == 0) {
            v1.erase(iter);
        }
    }
#endif
#if 1
    // while loop is better
    auto iter = v1.begin();
    while (iter != v1.end()) {
        if (*iter % 2 == 0) {
            // return reference of iter is very important to resolve
            // iterator failure problem.
            iter = v1.erase(iter);
        } else {
            iter++;
        }
    }
#endif
    cout << "after  remove even number: ";
    for (int item: v1) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
