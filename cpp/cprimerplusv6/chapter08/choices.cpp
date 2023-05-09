/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：choices.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>

template<typename T>
void show_array(T arr[], int n);

template<typename T>
void show_array(T * arr[], int n);

template <typename T> void recycle (T t);
template <typename T> void recycle (T * t);

struct debts {
    char name[50];
    double amout;
};

struct blot {
    int a;
    char b[10];
};

int main(){
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amout;
    }
    show_array(things, 6);
    show_array(pd, 3);

    blot ink = {25, "spots"};
    recycle(ink);
    recycle(&ink);

    return 0;
}

template <typename T>
void show_array(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename T>
void show_array(T* arr[], int n) {
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}

template <typename T> void recycle (T t) {
    using namespace std;
    cout << "out parameter is not pointer!" << endl;
}

template <typename T> void recycle (T * t) {
    using namespace std;
    cout << "out parameter is pointer!" << endl;
}