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

class Result {
public:
    Result() {}
    ~Result() {}
    void set_info(const std::string& info) {
        info_ = info;
    }
    void set_res() {
        set_info("task done!");
    }
private:
    std::string info_;
};

int main() {
#if 0
    Sub s1(1, 2);
    std::cout << s1.get_number() << std::endl;
    Sub s2(2, 3);
    std::cout << s2.get_number() << std::endl;
    Sub s3(3, 4);
    std::cout << s3.get_number() << std::endl;
#endif
#if 0
    {
        Result s1;
        s1.set_res();
        Result s2;
        s2.set_res();
        Result s3;
        s3.set_res();
        Result s4;
        s4.set_res();
    }
#endif

    std::string* s1 = new std::string("hello");
    std::string* s2 = new std::string("hello");
    delete s1;
    delete s2;

    return 0;
}