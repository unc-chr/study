/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：historical_person.h
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once
#include "human.h"
#include "card.h"

#include <iostream>

class HistoricalPerson : public Card, public Human {
    private:
        std::string deathDate;
        std::string dynasty;
    public:
        virtual ~HistoricalPerson() {}
        virtual std::string get_age();
        virtual std::string get_sub_title();
        virtual int32_t make_title(std::string& content);
        virtual int32_t make_card(std::string& content);
};