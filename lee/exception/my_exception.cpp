/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vector.cpp
*   Author：leekaihua
*   Date：20240701
*   Brife：
*



*/
#include "my_exception.h"

namespace lee {
namespace exception {

out_of_vector_range::out_of_vector_range(size_t pos, int range) {
    _message = "Argu: ";
    _message += std::to_string(pos) + " exceed curr range: 0~" + std::to_string(range);
}

const char* out_of_vector_range::what() const noexcept {
    return _message.c_str();
}

}
}
