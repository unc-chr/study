/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：class.h
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#ifndef CLASSIC2_H_
#define CLASSIC2_H_

class Cd {
    private:
        char* performers;
        char* label;
        int selections;
        double playtime;
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
        char* main_works;
    public:
        Classic(char* s1, char* s2, char* s3, int n, double x);
        Classic(const Cd& c, char* s);
        Classic();
        ~Classic();
        void Report() const;
        Classic& operator=(const Classic&);
};

#endif