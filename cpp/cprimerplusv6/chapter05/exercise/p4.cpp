/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>
int main(){
    using namespace std;
    double daphne_account = 100;
    double cleo_account = 100;
    int i = 0;
    while (daphne_account >= cleo_account) {
        daphne_account += 10;
        cleo_account *= 1.05;
        i++;
        cout << "year: " << i << " daphne_account is: " << daphne_account;
        cout << " and cleo_account is: " << cleo_account << endl;
    }
    cout << "year: " << i << " cleo_accout has exceed daphne_account. Congratulations!" << endl;
    cout << "Done!" << endl;

    return 0;
}