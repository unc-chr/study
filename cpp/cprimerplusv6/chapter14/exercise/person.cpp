/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：person.cpp
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#include "person.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

void Person::get() {
    std::cout << "Enter your first name: ";
    getline(std::cin, first_name);
    std::cout << "Enter your last name: ";
    getline(std::cin, last_name);
}

void Person::data() const {
    std::cout << "name: " << first_name
        << " " << last_name << std::endl;
}

void Person::show() const {
    data();
}

void Person::set() {
    get();
}

void Gunslinger::get() {
    std::cout << "Enter your draw time: ";
    std::cin >> draw_time;
    std::cout << "Enter your nick number on your gun: ";
    std::cin >> num_nick;
}

void Gunslinger::data() const {
    std::cout << "draw time: " << draw_time << std::endl;
    std::cout << "dick number on gun: " << num_nick << std::endl;
}

double Gunslinger::draw() const {
    return draw_time;
}

void Gunslinger::show() const {
    Person::data();
    data();
}

void Gunslinger::set() {
    Person::get();
    get();
}

void PokerPlayer::get() {
}

void PokerPlayer::data() const {
    std::cout << "Your drawed poker: " << draw() << std::endl;
}

int PokerPlayer::draw() const {
    // std::srand(std::time(0));
    return (std::rand() % 52 + 1);
}

void PokerPlayer::show() const {
    Person::data();
    data();
}

void PokerPlayer::set() {
    Person::get();
    get();
}

void BadDude::get() {}

void BadDude::data() const {
    std::cout << "gun draw time: " << gdraw() << std::endl;
    std::cout << "poker draw value: " << cdraw() << std::endl;
}

double BadDude::gdraw() const {
    Gunslinger::draw();
}

int BadDude::cdraw() const {
    PokerPlayer::draw();
}

void BadDude::set() {
    Person::get();
    Gunslinger::get();
    PokerPlayer::get();
    get();
}

void BadDude::show() const {
    Person::data();
    Gunslinger::data();
    PokerPlayer::data();
    data();
}