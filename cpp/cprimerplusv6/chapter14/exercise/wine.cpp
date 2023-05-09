/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：wine.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "wine.h"
#include "pairs.h"
#include <iostream>
#include <string>

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) {
    label = l;
    years = y;
    // year_to_bottles = Pair<ArrayInt, ArrayInt>(ArrayInt(y), ArrayInt(y));
    year_to_bottles.first() = ArrayInt(y);
    year_to_bottles.second() = ArrayInt(y);
    for (int i = 0; i < y; i++) {
        year_to_bottles.first()[i] = yr[i];
        year_to_bottles.second()[i] = bot[i];
    }
}

Wine::Wine(const char* l, int y) {
    label = l;
    years = y;
    // year_to_bottles = Pair<ArrayInt, ArrayInt>(ArrayInt(y), ArrayInt(y));
    year_to_bottles.first() = ArrayInt(y);
    year_to_bottles.second() = ArrayInt(y);
}

void Wine::Getbottles() {
    std::string wine_label = Label();
    std::cout << "Enter " << wine_label << " data for "
        << years << " year(s):" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "Enter years: ";
        std::cin >> year_to_bottles.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> year_to_bottles.second()[i];
    }
}

const std::string& Wine::Label() const {
    return label;
}

int Wine::sum() const {
    return year_to_bottles.second().sum();
}

void Wine::show_wine() const {
    std::cout << "wine: " << Label() << std::endl;
    std::cout <<  "\tYear\tBottles" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "\t" << year_to_bottles.first()[i]
            << "\t" << year_to_bottles.second()[i]
            << std::endl;
    }
    std::cout << std::endl;
}