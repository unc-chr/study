/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：dma.cpp
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#include "dma.h"
#include <cstring>

using std::strlen;
using std::strcpy;
using std::strncpy;
using std::cout;

DMA::DMA(const char* l, int r) {
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA& d) {
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    rating = d.rating;
}

DMA::~DMA() {
    delete [] label;
}

DMA& DMA::operator=(const DMA& d) {
    if (this == &d) {
        return *this;
    }
    delete [] label;
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    rating = d.rating;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const DMA& d) {
    os << "Label: " << d.label << std::endl;
    os << "Rating: " << d.rating << std::endl;
    return os;
}

baseDMA::baseDMA(const char* l, int r) : DMA(l, r) {}

baseDMA::baseDMA(const baseDMA& d) : DMA(d) {}

baseDMA::~baseDMA() {}

baseDMA& baseDMA::operator=(const baseDMA& bs) {
    if (this == &bs) {
        return *this;
    }
    DMA::operator=(bs);
    return *this;
}

void baseDMA::view() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& d) {
    os << (const DMA&) d;
    return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) : DMA(l, r) {
    strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const DMA& rs) : DMA(rs) {
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA(){}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
    os << (const DMA&) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::view() const {
    std::cout << *this;
}

hasDMA::hasDMA(const char* s, const char* l, int r) : DMA(l, r) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const DMA& rs) : DMA(rs) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs) : DMA(hs) {
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs) {
    if (this == &hs) {
        return *this;
    }
    DMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::view() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
    os << (const DMA&) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}