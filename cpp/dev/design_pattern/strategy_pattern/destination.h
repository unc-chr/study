/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：attraction.h
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once
#include <card.h>
#include <POI.h>

class Destination : public Card, public POI {
    private:
        std::string sub_scenic;
        std::string dest_type;
    public:
        virtual std::string make_card();
};