/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stringbad.h
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

#include <iostream>

class StringBad {
    private:
        char* str;  // pointer to string
        int len;    // length of string
        static int num_string;  // number of objects
    public:
        StringBad(const char* s);
        StringBad();
        ~StringBad();
        StringBad(const StringBad&);
        StringBad& operator=(const StringBad&);
        friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

#endif