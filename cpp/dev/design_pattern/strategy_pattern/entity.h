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

class Entity {
    private:
        std::string name;
        std::string desc;
    public:
        virtual std::string get_name() {
            return name;
        }
        virtual std::string get_desc() {
            return desc;
        }
        virtual std::string get_sub_title() = 0;
};