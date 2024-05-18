/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：customer.cpp
*   Author：leekaihua
*   Date：2023年03月19日
*   Brife：
*



*/
#include "customer.h"
#include <cstdlib>

// 随机生成一个完成交易需要消耗的时间
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}