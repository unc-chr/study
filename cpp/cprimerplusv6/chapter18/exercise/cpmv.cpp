/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：cmpv.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/
#include <string>
#include <iostream>
#include "cpmv.h"

Cpmv::Cpmv() {
    pi = new Info;
    pi->qcode = "qcode";
    pi->zcode = "zcode";
    std::cout << "Default constructor called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
}

Cpmv::Cpmv(std::string q, std::string z) {
    pi = new Info;
    pi->qcode = q; 
    pi->zcode = z;
    std::cout << "q z constructor called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
}

Cpmv::Cpmv(const Cpmv& cp) {
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    std::cout << "copy constructor called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
}

Cpmv::Cpmv(Cpmv&& mv) {
    pi = mv.pi;
    mv.pi = nullptr;
    std::cout << "move constructor called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
}

Cpmv::~Cpmv() {
    std::cout << "destructor called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
    delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) {
    if (this == &cp) {
        return *this;
    }
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;

    std::cout << "copy = called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv) {
    if (this == &mv) {
        return *this;
    }
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;

    std::cout << "move = called finished."
        << " pi.address: " << (void*)pi
        << std::endl;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const {
    Cpmv temp;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    std::cout << "+ called finished."
        << " temp.pi.address: " << (void*)temp.pi
        << std::endl;
    return temp;
}

void Cpmv::Display() const {
    std::cout << "code: " << pi->qcode
        << ", zcode: " << pi->zcode
        << ",pi.address: " << (void*)pi
        << std::endl;
    std::cout << std::endl;
}