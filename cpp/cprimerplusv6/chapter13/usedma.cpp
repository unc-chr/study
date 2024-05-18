/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：usedma.cpp
*   Author：leekaihua
*   Date：2022年01月08日
*   Brife：
*



*/
#include <iostream>
#include "dma.h"

int main() {
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "Displaying baseDma objects:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA objects:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA objects:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    return 0;
}