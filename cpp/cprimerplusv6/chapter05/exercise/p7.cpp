/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2021年12月07日
*   Brife：
*



*/
#include<iostream>
#include<string>
int main(){
    using namespace std;
    struct car
    {
        /* data */
        string brand;
        int year;
    };
    
    int num_car;
    cout << "Enter num of cars: ";
    cin >> num_car;
    cin.get();

    car * cars = new car[num_car];
    for (int i = 0; i < num_car; i++) {
        cout << "Car #" << i + 1 << endl;
        cout << "Enter car's brand: ";
        getline(cin, cars[i].brand);
        cout << "Enter car's year: ";
        cin >> cars[i].year;
        cin.get();
    }

    cout << "Here is your collections:" << endl;
    for (int i = 0; i < num_car; i++){
        cout << (cars + i)->year << " " << (cars + i)->brand << endl;
    }
    cout << "Done" << endl;
    return 0;
    
}