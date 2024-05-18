/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>
using namespace std;
#include<cstring>

struct stringy {
    char * str;
    int ct;
};

void set(stringy&, const char testing[]);
void show(const char[], int n = 1);
void show(const stringy&, int n = 1);

int main(){
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy& ins, const char testing[]) {
    int length = strlen(testing);
    ins.str = new char[length];
    for (int i = 0; i < length; i++) {
        ins.str[i] = testing[i];
    }
    ins.ct = length;
}

void show(const char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr << endl;
    }
    cout << endl;
}

void show(const stringy& ins, int n) {
    for (int i = 0; i < n; i++) {
        cout << ins.str << endl;
    }
    cout << endl;
}