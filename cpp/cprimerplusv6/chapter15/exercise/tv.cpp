/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：tv.cpp
*   Author：leekaihua
*   Date：2022年01月17日
*   Brife：
*



*/
#include "tvfm.h"
#include <iostream>

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else {
        return false;
    }
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else {
        return false;
    }
}

void Tv::chanup() {
    if (channel < maxchannel) {
        channel++;
    } else {
        channel = 1;
    }
}

void Tv::chandown() {
    if (channel > 1) {
        channel--;
    } else {
        channel = maxchannel;
    }
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "tv" : "DVD") << endl;
    }
}

void Tv::switch_inter_mode(Remote& r) const {
    if (state == On) {
        r.inter_mode = (r.inter_mode == NORMAL) ? INTERACT : NORMAL;
    }
}

void Remote::show_mode() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "interact = " << (inter_mode == NORMAL ? "NORMAL" : "INTERACT") << endl;
    }
}

void Remote::switch_inter_mode(Tv& t) const {
    if (t.ison()) {
        inter_mode = ((inter_mode == NORMAL ? INTERACT : NORMAL));
    }
}