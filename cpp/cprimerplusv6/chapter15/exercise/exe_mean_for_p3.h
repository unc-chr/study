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

class Bad_mean : public std::logic_error {
    private:
        double a;
        double b;
    public:
        Bad_mean(const std::string& s, double m_a, double m_b) : logic_error(s), a(m_a), b(m_b) {};
        void report();
        virtual const char* what();
};

class Bad_hmean : public Bad_mean {
    public:
        Bad_hmean(const std::string& s, double m_a, double m_b) : Bad_mean(s, m_a, m_b) {};
        virtual const char* what();
};

class Bad_gmean : public Bad_mean {
    public:
        Bad_gmean(const std::string& s, double m_a, double m_b) : Bad_mean(s, m_a, m_b) {};
        virtual const char* what();
};