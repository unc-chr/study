/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

long convert(long);

int main() {
    using namespace std;

    cout << "Input distance: ";
    long dis;
    cin >> dis;
    long yard = convert(dis);
    cout << dis << " = " << yard << " yards." << endl;

    return 0;
}

long convert(long dis) {
    return dis * 220;
}