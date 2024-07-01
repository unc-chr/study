/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：twotemps.cpp
*   Author：leekaihua
*   Date：2021年12月16日
*   Brife：
*



*/
#include <iostream>
template <typename T>
void diy_swap(T &a, T &b);

template <typename T>
void diy_swap(T *a, T *b, int n);

template <typename T, typename U>
void diy_swap(T* a, T* b, U c, int n);

void show(int a[]);
const int LIM = 8;

int main(){
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int diy_swapper:\n";
    diy_swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[LIM] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[LIM] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays:\n";
    show(d1);
    show(d2);
    diy_swap(d1, d2, LIM);
    cout << "diy_swapped array:\n";
    show(d1);
    show(d2);

    double u = 1.001;
    cout << "diy_swapped array again:\n";
    diy_swap(d1, d2, u, LIM);
    show(d1);
    show(d2);

    return 0;
}

template <typename T>
void diy_swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void diy_swap(T* a, T* b, int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template <typename T, typename U>
void diy_swap(T* a, T* b, U c, int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    std::cout << c << std::endl;
    std::cout << "this T and U instance" << std::endl;
}

void show(int a[]) {
    using namespace std;
    cout << a[0] << a[1] << '/';
    cout << a[2] << a[3] << '/';
    for (int i = 4; i < LIM; i++) {
        cout << a[i];
    }
    cout << endl;
}