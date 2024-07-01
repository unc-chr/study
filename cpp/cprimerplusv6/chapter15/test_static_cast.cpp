/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test_static_cast.cpp
*   Author：leekaihua
*   Date：20240629
*   Brife：
*



*/
#include <iostream>
#include <typeinfo>

int main() {
    int a = 1;
    double b = static_cast<int>(a);
    std::cout << b << std::endl;
    const std::type_info& type = typeid(b);
    std::cout << "var b = " << b << ", type = " << type.name() << std::endl;

    // invalid static_cast from type int* to type double*
    // int* p_a_int = &a;
    // double* p_a_double = static_cast<double*>(p_a_int);

    return 0;
}