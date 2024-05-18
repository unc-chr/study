/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2021年12月15日
*   Brife：
*



*/
#include<iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box box1);
void calc_volume(box * box2);

int main(){
    box box1 = {"likaihua", 1, 1, 1, 0};
    box box2 = {"likaihua1", 11, 11, 11, 0};
    calc_volume(&box1);
    show_box(box1);
    calc_volume(&box2);
    show_box(box2);

    return 0;
}

void show_box(box box1) {
    std::cout << "The box of " << box1.maker << std::endl;
    std::cout << "   height:" << box1.height << std::endl;
    std::cout << "   width:" << box1.width << std::endl;
    std::cout << "   length:" << box1.length << std::endl;
    std::cout << "   volume:" << box1.volume << std::endl;
}

void calc_volume(box * box2) {
    box2->volume = box2->height * box2->length * box2->length;
}