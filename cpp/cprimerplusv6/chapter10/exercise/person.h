/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：Person.h
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#pragma once
#include <string>

class Person {
    private:
        static const int LIMIT = 25;
        std::string lname;
        char fname[LIMIT];
    public:
        Person() {lname = ""; fname[0] = '\0';}
        Person(
            const std::string& ln,
            const char* fn = "Heyyou"
        );
        void Show() const;
        void FormalShow() const;
};