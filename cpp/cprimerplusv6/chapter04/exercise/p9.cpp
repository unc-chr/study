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
    CandyBar * snacks = new CandyBar[3];
    snacks->brand = "Mocha Munch1";
    snacks->weight = 2.4;
    snacks->calorie = 350;

    (snacks + 1)->brand = "Mocha Munch1";
    (snacks + 1)->weight = 2.5;
    (snacks + 1)->calorie = 351;

    (snacks + 2)->brand = "Mocha Munch1";
    (snacks + 2)->weight = 2.6;
    (snacks + 2)->calorie = 352;

    cout << "snack info" << endl;
    cout << "snack's brand: " << snacks->brand << endl;
    cout << "snack's weight: " << snacks->weight << endl;
    cout << "snack's calorie: " << snacks->calorie << endl;

    cout << "snack info" << endl;
    cout << "snack's brand: " << (snacks+1)->brand << endl;
    cout << "snack's weight: " << (snacks+1)->weight << endl;
    cout << "snack's calorie: " << (snacks+1)->calorie << endl;

    cout << "snack info" << endl;
    cout << "snack's brand: " << (snacks+2)->brand << endl;
    cout << "snack's weight: " << (snacks+2)->weight << endl;
    cout << "snack's calorie: " << (snacks+2)->calorie << endl;

    return 0;
}