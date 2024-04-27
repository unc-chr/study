/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：factory.cpp
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#include "factory.h"

std::unordered_map<std::string, Card*> Factory::process_handle;

Factory::~Factory() {
    delete process_handle["star_person"];
    delete process_handle["historical_person"];
}

Card* Factory::get_instance(std::string& request_type) {
    if (request_type == "star_person" && process_handle.find(request_type) == process_handle.end()) {
        process_handle["star_person"] = new StarPerson();
    }
    if (request_type == "historical_person" && process_handle.find(request_type) == process_handle.end()) {
        process_handle["historical_person"] = new HistoricalPerson();
    }
    return process_handle[request_type];
}