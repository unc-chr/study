/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p5.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>

template<typename T>
T max5(T arr[]);

int main(){
    using namespace std;
    int arr_int[] = {1, 2, 4, 5, 66};
    cout << "Max int is " << max5(arr_int) << endl;
    double arr_double[] = {2.33, 4.55, 1.01, 55.3, 33.2};
    cout << "Max double is " << max5(arr_double) << endl;

    return 0;
}

template<typename T>
T max5(T arr[]) {
    T the_max = arr[0];
    for (int i = 0; i < 5; i++) {
        if (arr[i] > the_max) {
            the_max = arr[i];
        }
    }

    return the_max;
}