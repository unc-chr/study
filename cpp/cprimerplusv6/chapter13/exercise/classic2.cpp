/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：classic.cpp
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#include "classic2.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Cd::Cd(char* s1, char* s2, int n, double x) {
    int len = strlen(s1);
    performers = new char[len + 1];
    strcpy(performers, s1);

    len = strlen(s2);
    label = new char[len + 1];
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d) {
    int len = strlen(d.performers);
    performers = new char[len + 1];
    strcpy(performers, d.performers);

    len = strlen(d.label);
    label = new char[len + 1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() {
    performers = 0;
    label = 0;
    selections = 0;
    playtime = 0;
}

Cd::~Cd() {
    cout << "Class Cd destructor function executeing..." << endl; 
    delete [] performers;
    delete [] label;
}

void Cd::Report() const {
    cout << "***************" << endl;
    cout << "   performers: " << performers << endl;
    cout << "   label: " << label << endl;
    cout << "   selections: " << selections << endl;
    cout << "   playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& c) {
    if (this == &c) {
        return *this;
    }

    delete performers;
    int len = strlen(c.performers);
    performers = new char[len + 1];
    strcpy(performers, c.performers);

    delete label;
    len = strlen(c.label);
    label = new char[len + 1];
    strcpy(label, c.label);

    selections = c.selections;
    playtime = c.playtime;
    return *this;
}

Classic::Classic(
        char* s1,
        char* s2,
        char* s3,
        int n,
        double x) : Cd(s2, s3, n, x) {
    int len = strlen(s1);
    main_works = new char[len + 1];
    strcpy(main_works, s1);
}

Classic::Classic(const Cd& c, char* s) : Cd(c) {
    int len = strlen(s);
    main_works = new char[len + 1];
    strcpy(main_works, s);
}

Classic::Classic() : Cd() {
    main_works = 0;
}

void Classic::Report() const {
    Cd::Report();
    cout << " main work is : " << main_works << endl;
}

Classic::~Classic() {
    cout << "Class Classic destructor function executeing..." << endl; 
    delete [] main_works;
}

Classic& Classic::operator=(const Classic& c) {
    if (this == &c) {
        return *this;
    }
    Cd::operator=(c); // mean *this = c
    int len = strlen(c.main_works);
    main_works = new char[len + 1];
    strcpy(main_works, c.main_works);
}