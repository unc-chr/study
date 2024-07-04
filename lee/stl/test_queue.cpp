/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_queue.h
*   Author：mayi
*   Date：20240703
*   Brife：
*



*/
#include <iostream>

#if 0
#include <queue>
using std::queue;
#endif

#if 1
#include "queue.h"
using lee::stl::queue;
#endif

using std::cout;
using std::endl;

int main() {
    queue<int> q;
    q.push(0);
    q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // test front function
    int res = q.front();
    cout << res << endl;

    // // test memory allocate and free
    // for (int i = 0; i < 5; i++) {
    //     q.push(i);
    //     q.pop();
    // }

    return 0;
}