/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_const_cast.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/

int main() {
    const in a = 10;
    // this is allowed in C
    // double* p1 = (double*)&a;
    // this is allowed in C
    // char* p1 = (char*)&a;
    // this is what we expected in C
    int* p1 = (int*)&a;
    int* p2 = const_cast<int*>(&a);
    *

    return 0;
}