/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：use_tv.cpp
*   Author：leekaihua
*   Date：2022年01月17日
*   Brife：
*



*/
#include "tvfm.h"
#include <iostream>

int main() {
    using std::cout;
    Tv s42;
    cout << "Initial setting for 42 TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted setting for 42 TV:\n";

    s42.chanup();
    cout << "\nAdjusted setting for 42 TV:\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42 setting after using remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58 setting:\n";
    s58.settings();

    return 0;
}