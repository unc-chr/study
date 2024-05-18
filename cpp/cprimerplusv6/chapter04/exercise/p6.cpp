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
    CandyBar snacks[3] = {
        {"Mocha Munch1", 2.3, 350},
        {"Mocha Munch2", 2.4, 351},
        {"Mocha Munch3", 2.5, 352}
    };

    cout << "snack info" << endl;
    cout << "snack's brand: " << snacks[0].brand << endl;
    cout << "snack's weight: " << snacks[0].weight << endl;
    cout << "snack's calorie: " << snacks[0].calorie << endl;

    cout << "snack info" << endl;
    cout << "snack's brand: " << snacks[1].brand << endl;
    cout << "snack's weight: " << snacks[1].weight << endl;
    cout << "snack's calorie: " << snacks[1].calorie << endl;

    cout << "snack info" << endl;
    cout << "snack's brand: " << snacks[2].brand << endl;
    cout << "snack's weight: " << snacks[2].weight << endl;
    cout << "snack's calorie: " << snacks[2].calorie << endl;
    return 0;
}