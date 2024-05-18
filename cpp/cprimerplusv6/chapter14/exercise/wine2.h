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
#include <string>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray{
    private:
        int years;
    public:
        Wine() {}
        Wine(const char* l, int y, const int yr[], const int bot[])
            : std::string(l), 
            years(y), 
            PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {};
        Wine(const char* l, int y)
            : std::string(l),
            years(y),
            PairArray(ArrayInt(y), ArrayInt(y)) {};
        void Getbottles();
        const std::string& Label() const;
        int sum() const;
        void show_wine() const;
};