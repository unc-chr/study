/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2021年12月06日
*   Brife：
*



*/
#include<iostream>
#include<string>

int main(){
    using namespace std;
    struct pizza {
        string company;
        double diameter;
        double weight;
    };

    pizza pizza1;
    cout << "Enter pizza company: " << endl;
    cin >> pizza1.company;
    cout << "Enter pizza diameter" << endl;
    cin >> pizza1.diameter;
    cout << "Enter pizza weight: " << endl;
    cin >> pizza1.weight;

    cout << "pizza's info" << endl;
    cout << "pizza's company: " << pizza1.company << endl;
    cout << "pizza's diameter: " << pizza1.diameter << endl;
    cout << "pizza's weight: " << pizza1.weight << endl;

    return 0;
}