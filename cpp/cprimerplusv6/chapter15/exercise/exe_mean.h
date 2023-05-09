/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：exe_mean.h
*   Author：leekaihua
*   Date：2023年03月15日
*   Brife：
*



*/
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bad_hmean : public std::logic_error {
    public:
        Bad_hmean(const std::string& s) : logic_error(s) {};
        // virtual ~Bad_hmean() {};
        const char* what();
};

class Bad_gmean : public std::logic_error {
    public:
        Bad_gmean(const std::string& s) : logic_error(s) {};
        // virtual ~Bad_gmean() {};
        const char* what();
};