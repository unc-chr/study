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
#include <string>
#include "dma.h"
const int CLASS_NUM = 4;

int main() {
    using namespace std;
    char temp_label[50];
    int temp_rating;
    int temp_class_type;
    DMA* DMA_array[CLASS_NUM];

    for (int i = 0; i < CLASS_NUM; i++) {
        cout << "Enter class label: ";
        cin.getline(temp_label, 50);
        cout << "Enter class rating: ";
        cin >> temp_rating;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA: ";
        while (cin >> temp_class_type && (
            temp_class_type != 1 && temp_class_type != 2 && temp_class_type != 3
        )) {
            cout << "Enter 1, 2 or 3: ";
        }
        cin.get();
        const char* label = temp_label;
        if (temp_class_type == 1) {
             DMA_array[i] = new baseDMA(label, temp_rating);
        } else if (temp_class_type == 2) {
            char temp_color[50];
            cout << "Enter the color: ";
            cin.getline(temp_color, 50);
            cout << "temp_color: ";
            cout << temp_color;
            const char* color = temp_color;
            DMA_array[i] = new lacksDMA(color, label, temp_rating);
        } else {
            char temp_style[50];
            cout << "Enter the style: ";
            cin.getline(temp_style, 50);
            const char* style = temp_style;
            DMA_array[i] = new hasDMA(style, label, temp_rating);
        }
    }
    cout << endl;
    for (int i = 0; i < CLASS_NUM; i++) {
        DMA_array[i]->view();
        cout << endl;
    }

    for (int i = 0; i < CLASS_NUM; i++) {
        delete DMA_array[i];
    }
    cout << "Done.\n";

    return 0;
}