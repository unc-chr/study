/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>

template<typename T>
void show_array(T arr[], int n);

template<typename T>
void show_array(T* arr[], int n);

template<typename T>
void sum_array(T arr[], int n);

template<typename T>
void sum_array(T* arr[], int n);

struct debts {
    /* data */
    char names[50];
    double amount;
};

int main(){
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_e[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

     for (int i = 0; i < 3; i++) {
         pd[i] = &mr_e[i].amount;
     }
     cout << "Listing Mr. E's counts of things:\n";
     show_array(things, 6);
     sum_array(things, 6);
     cout << endl;

     cout << "Listing Mr. E's debts:\n";
     show_array(pd, 3);
     sum_array(pd, 3);

     return 0;
}

template<typename T>
void show_array(T arr[], int n){
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template<typename T>
void show_array(T* arr[], int n) {
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}

template<typename T>
void sum_array(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    if (n == 1) {
        cout << "Sum is " << arr[0] << endl;
    } else {
        T sum_arr = arr[0];
        for (int i = 1; i < n; i++) {
            sum_arr += arr[i];
        }
        cout << "Sum is " << sum_arr << endl;
    }
}

template<typename T>
void sum_array(T* arr[], int n) {
    using namespace std;
    cout << "template B\n";
    if (n == 1) {
        cout << "Sum is " << *arr[0] << endl;
    } else {
        T sum_arr = *arr[0];
        for (int i = 1; i < n; i++) {
            sum_arr += *arr[i];
        }
        cout << "Sum is " << sum_arr << endl;
    }
}