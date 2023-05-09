/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：error4.cpp
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#include "exe_mean.h"

const char* Bad_hmean::what() {
    return "report: hmean error. argu a = argu b";
}

const char* Bad_gmean::what() {
    return "report: gmean error. argu a < 0 or argu b < 0";
}