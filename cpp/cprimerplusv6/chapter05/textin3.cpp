/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：textin3.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include <iostream>

int main(){
    using namespace std;
    char ch;
    int count = 0;
    while(cin.get(ch)) {
        count++;
        cout << ch;
    }
    cout << endl;
    cout << "num of characters is: " << count << endl;

    return 0;
}