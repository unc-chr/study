/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vector.h
*   Author：leekaihua
*   Date：20240630
*   Brife：
*
*   reference: https://en.cppreference.com/w/cpp/container/vector
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

namespace lee {
namespace exception {

class out_of_vector_range : public std::exception {
public:
    out_of_vector_range(size_t pos, int range);
    ~out_of_vector_range() = default;
    const char* what() const noexcept override;
private:
    std::string _message;
};

class empty_container : public std::exception {
public:
    empty_container (const char* msg);
    ~empty_container () = default;
    const char* what() const noexcept override;
private:
    const char* _msg;
};

}
}