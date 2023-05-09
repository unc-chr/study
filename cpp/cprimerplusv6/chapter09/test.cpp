/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2021年12月29日
*   Brife：
*



*/
#include <iostream>
int main(){
    using namespace std;
    for (int count = 0; count < 10; count++) {
        int i;
        int j;
        cout << "i = " << i << ", address is " << &i << endl;
        cout << "j = " << j << ", address is " << &j << endl;
    }

    int k;
    cout << "k = " << k << ", address is " << &k << endl;

    return 0;
}