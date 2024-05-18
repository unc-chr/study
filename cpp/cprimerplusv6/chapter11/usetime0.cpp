/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：use_time.cpp
*   Author：leekaihua
*   Date：2023年03月08日
*   Brife：
*



*/

#include "mytime0.h"
#include <iostream>

int main() {
    using namespace std;
    Time time1;
    time1.show_time();

    Time time2(1, 30);
    time2.show_time();

    time2.add_hours(3);
    time2.show_time();

    time2.add_minutes(55);
    time2.show_time();

    Time time3(2, 33);
    Time new_time = time3.sum(time2);
    new_time.show_time();
    
    return 0;
}
