/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2021年12月15日
*   Brife：
*



*/
#include<iostream>
long long diy_fac(int num);
int main(){
    using namespace std;
    int num;
    cout << "Enter a num:";
    while(cin >> num) {
        long long result = diy_fac(num);
        cout << "The factorial of " << num << " is " << result << endl;
        cout << "Enter another num:";
    }

    return 0;
}

long long diy_fac(int num) {
    if (num == 0) {
        return 1;
    }
    return num * diy_fac(num - 1);
}