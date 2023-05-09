/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include <iostream>
int main(){
    using namespace std;
    int num;
    cout << "Enter num: ";
    cin >> num;

    if (num == 0) {
        cout << "0! = 1" << endl;
        return 0;
    }

    long double result = 1;
    for (int i = 1; i <= num; i++) {
        result = result * i;
        cout << i << "!= " << result << endl;
    }
    return 0;
}
