/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：queue_test.cpp
*   Author：leekaihua
*   Date：2023年03月19日
*   Brife：
*



*/

#include <iostream>
#include <queue>

int main() {
    using namespace std;
    queue<int> line;

    line.push(15);
    line.push(16);
    line.push(17);
    line.push(18);
    line.push(19);
    cout << "line size = " << line.size() << endl;

    line.pop();
    cout << "line size = " << line.size() << endl;

    int line_front = line.front();
    cout << "line size = " << line.size() << endl;

    return 0;
}