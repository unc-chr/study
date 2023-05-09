/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p1.cpp
*   Author：leekaihua
*   Date：2021年12月31日
*   Brife：
*



*/
#include "golf.h"
#include <iostream>
#include <cstring>
int main(){
    using std::cout;
    using std::endl;

    golf golf1;
    setgolf(golf1, "leekaihua", 1);
    showgolf(golf1);

    golf people[5];
    int i = 0;
    while (i < 5) {
        golf temp_player;
        int proc_code = setgolf(temp_player);
        if (proc_code == 0) {
            break;
        }
        people[i] = temp_player;
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (strlen(people[j].fullname) == 0) {
            continue;
        }
        showgolf(people[j]);
    }

    return 0;
}