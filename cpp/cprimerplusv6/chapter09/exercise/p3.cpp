/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include <iostream>
#include <new>

struct chaff {
    char dross[20];
    int slag;
};

void show_chaff(const chaff&);
int set_chaff(chaff&);
int main() {
    char buffer[100];
    chaff* ins1 = new(buffer)chaff[2];
    set_chaff(ins1[0]);
    set_chaff(ins1[1]);
    for (int i = 0; i < 2; i++) {
        show_chaff(ins1[i]);
    }

    return 0;
}

int set_chaff(chaff& ins) {
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter dross: ";
    cin.getline(ins.dross, 20);
    if (ins.dross[0] == '\0') {
        return 1;
    }
    cout << "Enter slag: ";
    cin >> ins.slag;
    cin.get();
    return 0;
}

void show_chaff(const chaff& ins) {
    using std::cout;
    using std::endl;
    if (ins.dross[0] != '\0') {
        cout << "The slag of " << ins.dross;
        cout << " is " << ins.slag << endl;
    }
}