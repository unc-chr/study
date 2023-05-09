/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2023年03月02日
*   Brife：
*



*/

#include <iostream>

void out1();
void out2();

int main() {
    using namespace std;
    out1();
    out1();
    out2();
    out2();

    return 0;
}

void out1() {
    using namespace std;
    cout << "Three blind mice" << endl;
}

void out2() {
    using namespace std;
    cout << "See how they run" << endl;
}