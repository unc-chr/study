/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：stringbad.h
*   Author：leekaihua
*   Date：2022年01月03日
*   Brife：
*



*/
#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;

class String {
    private:
        char* str;  // pointer to string
        int len;    // length of string
        static int num_string;  // number of objects
        static const int CINLIM = 80;
    public:
        String(const char* s);
        String();
        String(const String&);
        ~String();
        int length() const {return len;}

        String& operator=(const String&);
        String& operator=(const char*);
        char& operator[](int i);
        const char& operator[](int i) const;
        String operator+(const String&) const;
        void stringlow();
        void stringup();
        int has(char) const;

        friend String operator+(const char*, const String&);
        friend bool operator<(const String& st, const String& st2);
        friend bool operator>(const String& st, const String& st2);
        friend bool operator==(const String& st, const String& st2);
        friend std::ostream& operator<<(std::ostream& os, const String& st);
        friend std::istream& operator>>(std::istream& os, String& st);

        static int HowMany();
};

#endif