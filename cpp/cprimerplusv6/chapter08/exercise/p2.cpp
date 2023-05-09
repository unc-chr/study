/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2021年12月26日
*   Brife：
*



*/
#include<iostream>
#include<string>

struct candy_bar {
    std::string brand;
    double heavy;
    int heat;
};

void set_candy_var(candy_bar&, 
    const char* brand = "Millennium Munch", 
    double heavy = 2.85, 
    int heat = 350);
void show_candy_var(const candy_bar&);

int main(){
    using namespace std;
    candy_bar ins1;
    set_candy_var(ins1, "mengniu");
    candy_bar ins2;
    set_candy_var(ins2, "yili", 2.90, 330);
    candy_bar ins3;
    set_candy_var(ins3, "telunsu", 3.00, 350);
    
    show_candy_var(ins1);
    show_candy_var(ins2);
    show_candy_var(ins3);

    return 0;
}

void set_candy_var(candy_bar& ins, const char* brand, double heavy, int heat) {
    ins.brand = brand;
    ins.heavy = heavy;
    ins.heat = heat;
}

void show_candy_var(const candy_bar& ins) {
    using namespace std;
    cout << ins.brand << " heavy is ";
    cout << ins.heavy << " and heat is ";
    cout << ins.heat << endl;
}