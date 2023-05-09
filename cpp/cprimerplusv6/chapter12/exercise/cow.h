/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：cow.h
*   Author：leekaihua
*   Date：2022年01月05日
*   Brife：
*



*/
#ifndef COW_H_
#define COW_H_

class Cow {
    private:
        char name[20];
        char* hobby;
        double weight;
    public:
        Cow();
        Cow(const char* nm, const char* ho, double wt);
        Cow(const Cow&);
        ~Cow();
        Cow& operator=(const Cow& c);
        void ShowCow() const;
};

#endif