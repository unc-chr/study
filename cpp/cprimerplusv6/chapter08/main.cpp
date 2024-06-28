/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：main.cpp
*   Author：leekaihua
*   Date：20240628
*   Brife：
*



*/

#include <iostream>

template <typename T>
bool compare(T a, T b);

int main() {
    bool result = compare(1, 2);
    if (result) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}