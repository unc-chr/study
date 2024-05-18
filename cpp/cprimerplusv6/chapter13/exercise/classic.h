/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：class.h
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd {
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
        static unsigned int num_of_cd;
    public:
        Cd(char* s1, char* s2, int n, double x);
        Cd(const Cd& d);
        Cd();
        ~Cd();
        virtual void Report() const;
        Cd& operator=(const Cd&);
};

class Classic : public Cd {
    private:
        char main_works[50];
        static unsigned int num_of_classic;
    public:
        Classic(char* s1, char* s2, char* s3, int n, double x);
        Classic(const Cd& c, char* s);
        Classic();
        ~Classic();
        virtual void Report() const;
        Classic& operator=(const Classic&);
};

#endif