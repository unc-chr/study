/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：star_person.h
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once
#include "human.h"
#include "card.h"

#include <iostream>

class StarPerson : public Card, public Human{
    private:
        std::string height;
        std::string occupation;
        std::string constellation;
        std::string works;
    public:
        virtual ~StarPerson() {};
        virtual std::string get_age();
        virtual std::string get_sub_title();
        virtual int32_t make_title(std::string& content);
        virtual int32_t make_card(std::string& content);
};