/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vertical_type.h
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once

#include <string>

class Card {
    private:
        std::string srcid;
    public:
        virtual ~Card() {};
        virtual int32_t make_title(std::string& content) = 0;
        virtual int32_t make_card(std::string& content) = 0;
};