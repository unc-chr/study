/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_vector.cpp
*   Author：leekaihua
*   Date：2024年03月24日
*   Brife：
*



*/
#include <iostream>

#include "vector.h"

using namespace lee::stl;

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.show();

    v.reserve(6);
    v.show();
    v.reserve(16);
    v.show();

    v.resize(3);
    v.show();

    cout << "front: " << v.front() << endl;
    cout << "back:" << v.back() << endl;

    try {
        int access_index[4] = {0, 1, 10, 17};
        int v_element = 0;
        for (int i = 0; i < 4; i++) {
            v_element = v.at(access_index[i]);
            cout << "access element by at(" << access_index[i] << "): " << v_element << endl;
            v_element = v[1];
            cout << "access element by [" << access_index[i] << "]: " << v_element << endl;
        }
    } catch (std::out_of_range& e) {
        cout << e.what() << endl;
    }
    // 如果没有异常处理
    // int v_element_2 = v.at(10);

    v.resize(18);
    v.show();

    v.pop_back();
    v.pop_back();
    v.show();

    Vector<int> v2;
    v2.push_back(11);
    v2.push_back(12);
    v2.push_back(13);

    v2.swap(v);
    cout << "vector v: " << endl;
    v.show();
    cout << "vector v2: " << endl;
    v2.show();

    Vector<int> v3;
    v3 = v2;
    cout << "vector v3: " << endl;
    v3.show();

    cout << "iter v" << endl;
    for (Vector<int>::Iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }
    cout << endl;

    v.insert(v.begin(), 0);
    v.show();

    cout << "v erase begin()+2" << endl;
    v.erase(v.begin() + 2);
    v.show();

    v.clear();
    v.show();

    return 0;
}