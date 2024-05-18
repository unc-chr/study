/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>
int count = 0;
void print(const char * str, int n = 0);

int main() {
    print("my", 2);
    print("name", 3);
    print("is", 5);
    print("leekaihua", 0);

    return 0;
}

void print (const char * str, int n) {
    using namespace std;
    count++;
    if (n != 0) {
        for (int i = 0; i < count; i++) {
            cout << str << "\t";
        }
        cout << endl;
    } else {
        cout << str << endl;
    }
}