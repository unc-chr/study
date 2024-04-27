/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：historical_person.cpp
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#include "historical_person.h"

std::string HistoricalPerson::get_age() {
    return "deathDate - birth_date";
}

std::string HistoricalPerson::get_sub_title() {
    return "age + jobs";
}

int32_t HistoricalPerson::make_title(std::string& content) {
    std::cout << "historical_person title: " << content << std::endl;
    return 0;
}

int32_t HistoricalPerson::make_card(std::string& content) {
    std::cout << "historical_person: " << content << std::endl;
    return 0;
}