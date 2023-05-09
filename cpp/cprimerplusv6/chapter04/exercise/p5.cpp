/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
#include<string>

int main(){
    using namespace std;
    struct CandyBar {
        string brand;
        double weight;
        int calorie;
    };
    CandyBar snack = {"Mocha Munch", 2.3, 350};

    cout << "snack info" << endl;
    cout << "snack's brand: " << snack.brand << endl;
    cout << "snack's weight: " << snack.weight << endl;
    cout << "snack's calorie: " << snack.calorie << endl;

    return 0;
}