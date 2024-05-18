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

    Golf golf1 = Golf("leekaihua", 1);
    golf1.showgolf();

    Golf golf2;
    golf2.showgolf();

    return 0;
}