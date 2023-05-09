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
    cout << "Enter num: " << endl;
    cin >> num;

    long long num_array[num+1];
    num_array[0] = 1;
    for (int i = 1; i <= num; i++) {
        num_array[i] = num_array[i-1] * i;
    }
    for (int i = 0; i <= num; i++) {
        cout << i << "! = " << num_array[i] << endl;
    }

    return 0;
}
