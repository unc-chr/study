/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：request.cpp
*   Author：leekaihua
*   Date：2024年04月27日
*   Brife：
*



*/
#include "factory.h"

#include <string>
#include <vector>

int main() {
    std::vector<std::vector<std::string>> request_pack;
    request_pack.push_back({"Andy Liu", "star_person"});
    request_pack.push_back({"Taylor Swift", "star_person"});
    request_pack.push_back({"Zhu Yuanzhang", "historical_person"});
    request_pack.push_back({"Li Shiming", "historical_person"});
    for (size_t i = 0; i < request_pack.size(); i++) {
        std::string content = request_pack[i][0];
        std::string request_type = request_pack[i][1];
        int32_t res = (Factory::get_instance(request_type))->make_card(content);
        if (res == 0) {
            std::cout << "process successfully!" << std::endl;
        } else {
            std::cout << "process failed!" << std::endl;
        }
    }

    return 0;
}