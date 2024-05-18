/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：tabtenn0.cpp
*   Author：leekaihua
*   Date：2023年10月21日
*   Brife：
*



*/
#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(
        const string& fn, const string& ln, bool ht)
        : firstname(fn), lastname(ln), hasTable(ht) {
    std::cout << "Class TableTennisPlayer: " << firstname << ", " << lastname
        << " created!" << std::endl;
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(
        unsigned int r, const string& fn,
        const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht) {
    rating = r;
}

RatedPlayer::RatedPlayer(
        unsigned int r, const TableTennisPlayer& tp) : TableTennisPlayer(tp) {
    rating = r;
}