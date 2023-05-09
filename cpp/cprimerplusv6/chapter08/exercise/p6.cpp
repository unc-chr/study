/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p6.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>
#include<cstring>

template<typename T>
T maxn(T arr[], int arr_length);
template <> char* maxn(char* arr[], int arr_length);

int main() {
    using namespace std;

    int arr_int[6] = {1, 5, 3, 2, 7, 9};
    int arr_int_length = sizeof(arr_int)/sizeof(arr_int[0]);
    int max_int = maxn(arr_int, arr_int_length);
    cout << "The max int is " << max_int << endl;

    double arr_double[4] = {1.22, 55.66, 6.7, 8.99};
    int arr_double_length = sizeof(arr_double)/sizeof(arr_double[0]);
    double max_double = maxn(arr_double, arr_double_length);
    cout << "The max double is " << max_double << endl;

    char* arr_str[6] = {
        "leekaihua",
        "leekaili",
        "People republic of china",
        "Beijing University of post and telecommunication",
        "School of Electronic Engineer",
        "class five"
    };
    char* the_longest =  maxn(arr_str, 6);
    cout << the_longest << endl;

    return 0;
}

template<typename T>
T maxn(T arr[], int arr_length) {
    T temp = arr[0];
    for (int i = 0; i < arr_length; i++) {
        if (arr[i] > temp) {
            temp = arr[i];
        }
    }

    return temp;
}

template<> char* maxn(char* arr[], int arr_length) {
    char* the_max = arr[arr_length - 1];
    for (int i = arr_length - 1; i >= 0; i--) {
        if (strlen(arr[i]) >= strlen(the_max)) {
            the_max = arr[i];
        }
    }

    return the_max;
}
