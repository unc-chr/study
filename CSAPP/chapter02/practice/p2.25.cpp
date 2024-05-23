/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.25.cpp
*   Author：leekaihua
*   Date：2023年09月12日
*   Brife：
*



*/
#include <iostream>

float sum_element(float a[], unsigned int length);

int main() {
    using std::cout;
    using std::endl;

    float a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // correct version 
    float result = sum_element(a, 15);
    // float result = sum_element(a, 0);
    
    cout << result << endl;
    return 0;
}

float sum_element(float a[], unsigned int length) {
    int i;
    float result = 0;

    for (int i = 0; i < length; i++) {
        result += a[i];
    }

    return result;
}