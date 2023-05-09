/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：error4.cpp
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#include "exe_mean_for_p3.h"
#include <iostream>

void Bad_mean::report() {
    std::cout << "arguments: " << a << ", " << b << std::endl;
}

const char* Bad_mean::what() {
    std::cout << "bad_mean::what" << std::endl;
    return "some error.";
}

const char* Bad_hmean::what() {
    std::cout << "bad_hmean::what" << std::endl;
    return "report hmean error. argu a = argu b";
}

const char* Bad_gmean::what() {
    std::cout << "bad_gmean::what" << std::endl;
    return "report gmean error. argu a < 0 or argu b < 0";
}