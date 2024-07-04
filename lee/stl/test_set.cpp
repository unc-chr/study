/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_set.cpp
*   Author：mayi
*   Date：20240704
*   Brife：
*



*/
#include <iostream>

#if 1
#include <set>
using std::set;
#endif

using std::cout;
using std::endl;

#define TEST_TIMES 20

int main() {
    // test construct
    set<int> s;
    // test insert
    for (int i = 0; i < TEST_TIMES; i++) {
        s.insert(rand() % 100 + 1);
    }
    s.insert(30);
    s.insert(30);
    s.insert(30);
    // test size
    cout << "insert " << TEST_TIMES << " numbers into set." 
            << " Actually " << s.size() 
            << " different number left." << endl;
    // test iterator traverse
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    // test iteratr failure
    for (auto iter = s.begin(); iter != s.end();) {
        if (*iter == 30) {
            iter = s.erase(iter);
        } else {
            ++iter;
        }
    }
    // test find
    auto iter = s.find(20);
    if (iter != s.end()) {
        s.erase(iter);
    }
    // test foreach with iterator
    for (int item: s) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}