/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：plorg.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/
#include "plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg() {
    strcpy(m_name, "Plorga");
    m_CI = 50;
}

Plorg::Plorg(char* name) {
    strcpy(m_name, name);
    m_CI = 50;
}

void Plorg::reset(int ci) {
    m_CI = ci;
}

void Plorg::report() {
    std::cout << m_name << " CI value = " << m_CI << std::endl;
}