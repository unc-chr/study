/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：factory.cpp
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#pragma once
#include "card.h"
#include "star_person.h"
#include "historical_person.h"

#include <unordered_map>
#include <string>

class Factory {
    private:
        static std::unordered_map<std::string, Card*> process_handle;
    private:
        Factory();
        ~Factory();
    public:
        static Card* get_instance(std::string& request_type);
};