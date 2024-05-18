/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：two_level_pointer.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    const int **pp2;
    int *p1;
    const int n=13;
    pp2=&p1;
    *pp2=&n;
    *p1=10;

    return 0;
}
