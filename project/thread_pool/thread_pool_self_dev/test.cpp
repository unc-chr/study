/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test.cpp
*   Author：leekaihua
*   Date：20240611
*   Brife：
*



*/
#include <iostream>

class Base {
public:
    Base() {
        number_++;
    }

    uint32_t get_number() {
        return number_;
    }
private:
    static uint32_t number_;
};

uint32_t Base::number_ = 0;

class Sub : public Base {
public:
    Sub(int arg1, int arg2) : arg1_(arg1), arg2_(arg2) {}
private:
    int arg1_;
    int arg2_;
};

int main() {
    Sub s1(1, 2);
    std::cout << s1.get_number() << std::endl;
    Sub s2(2, 3);
    std::cout << s2.get_number() << std::endl;
    Sub s3(3, 4);
    std::cout << s3.get_number() << std::endl;

    return 0;
}