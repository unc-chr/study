/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vertical_type_1_level.h
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once

#include <string>

#include "entity.h"

class POI : public Entity {
    private:
        std::string address;
    public:
        virtual std::string get_add() = 0;
};