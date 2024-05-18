/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：wine.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "pairs.h"
#include "wine2.h"
#include <iostream>
#include <string>

void Wine::Getbottles() {
    std::string wine_label = Label();
    std::cout << "Enter " << wine_label << " data for "
        << years << " year(s):" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "Enter years: ";
        std::cin >> PairArray::first().operator[](i);
        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second()[i];
    }
}

// 返回对象中 string 表示的 label。
const std::string& Wine::Label() const {
    return (const std::string&) *this;
}

// 
int Wine::sum() const {
    return PairArray::second().sum();
}

void Wine::show_wine() const {
    std::cout << "wine: " << Label() << std::endl;
    std::cout <<  "\tYear\tBottles" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "\t" << PairArray::first()[i]
            << "\t" << PairArray::second()[i]
            << std::endl;
    }
    std::cout << std::endl;
}