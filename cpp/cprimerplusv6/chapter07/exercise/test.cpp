/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2023年03月06日
*   Brife：
*



*/

#include <iostream>

int main() {
    using namespace std;

    double x = 0;
    if (x == 0) {
        cout << "Yes" << endl;
    }

    double diff = x - 0;
    cout << "diff: " << diff << endl;
    return 0;
}
