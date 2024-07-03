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

class Video: public Entity {
    private:
        std::string duration;
    public:
        virtual std::string get_duration() = 0;
};