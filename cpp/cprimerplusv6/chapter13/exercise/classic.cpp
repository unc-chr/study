/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：classic.cpp
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#include "classic.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

unsigned int Cd::num_of_cd = 0;
unsigned int Classic::num_of_classic = 0;

Cd::Cd(char* s1, char* s2, int n, double x) {
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
    num_of_cd++;
    cout << "Class Cd construcor function executing..."
        << num_of_cd << " instance created. "
        << "performers: " << performers << endl;
}

Cd::Cd(const Cd& d) {
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    num_of_cd++;
    cout << "Class Cd copy construcor function executing..."
        << num_of_cd << " instance created. "
        << "performers: " << performers << endl;
}

Cd::Cd() {
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
    cout << "Class Cd default construcor function executing..."
        << num_of_cd << " instance created. "
        << "performers: " << performers << endl;
}

Cd::~Cd() {
    num_of_cd--;
    cout << "Class Cd destructor function executeing..."
        << num_of_cd << " instance left."
        << "performers: " << performers << endl;
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
    strcpy(performers, c.performers);
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
    strcpy(main_works, s1);
    num_of_classic++;
    cout << "Class Classic construcor function executing..."
        << num_of_classic << " instance created. "
        << "main_works: " << main_works << endl;
}

Classic::Classic(const Cd& c, char* s) : Cd(c) {
    strcpy(main_works, s);
    num_of_classic++;
    cout << "Class Classic copy construcor function executing..."
        << num_of_classic << " instance created. "
        << "main_works: " << main_works << endl;
}

Classic::Classic() : Cd() {
    main_works[0] = '\0';
    num_of_classic++;
    cout << "Class Classic default construcor function executing..."
        << num_of_classic << " instance created.";
}

void Classic::Report() const {
    Cd::Report();
    cout << "   main work is : " << main_works << endl;
}

Classic::~Classic() {
    num_of_classic--;
    cout << "Class Classic destructor function executeing..."
        << num_of_classic << " instance left."
        << "main_works: " << main_works << endl;
}

Classic& Classic::operator=(const Classic& c) {
    if (this == &c) {
        return *this;
    }
    Cd::operator=(c); // mean *this = c
    strcpy(main_works, c.main_works);
}