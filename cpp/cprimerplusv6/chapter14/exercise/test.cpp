/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2023年03月24日
*   Brife：
*



*/

#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    using namespace std; 

    for (int i = 0; i < 10; i++) {
        srand(time(0));
        cout << "#1: " << rand() % 52 + 1 << endl;
    }
    
    return 0;
}