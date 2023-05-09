/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：wine.h
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#pragma once
#include "pairs.h"
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
    private:
        std::string label;
        PairArray year_to_bottles;
        int years;
    public:
        Wine() {}
        Wine(const char* l, int y, const int yr[], const int bot[]);
        Wine(const char* l, int y);
        void Getbottles();
        const std::string& Label() const;
        int sum() const;
        void show_wine() const;
};