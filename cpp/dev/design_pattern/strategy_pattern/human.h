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
#include "human_schema.h"

class Human: public Entity {
    private:
        std::string age;
        std::string birthDate;
        std::string relation;
        human::gender gender;
        human::alive status_alive;
    public:
        virtual std::string get_age() = 0;
};