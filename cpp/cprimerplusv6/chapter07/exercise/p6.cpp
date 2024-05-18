/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2021年12月15日
*   Brife：
*



*/
#include<iostream>

using namespace std;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int array_size);
void reverse_array(double arr[], int array_size);

int main(){
    const int LIMIT = 10;
    double score[10];

    int array_size = fill_array(score, LIMIT);
    show_array(score, array_size);

    reverse_array(score, array_size);
    show_array(score, array_size);

    reverse_array(score + 1, array_size - 2);
    show_array(score, array_size);

    cout << "Done!" << endl;

    return 0;
}

int fill_array(double arr[], int limit) {
    double temp_score;
    int i = 0;
    cout << "Enter " << limit << " numbers:" << endl;
    for (i = 0; i < limit; i++) {
        cout << "Enter score #" << i + 1 << ":";
        cin >> temp_score;
        if (!cin) {
            cin.clear();
            while(cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; input process terminated." << endl;
            break;
        } else {
            arr[i] = temp_score;
        }
    }

    return i;
}

void show_array(const double arr[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(double arr[], int array_size) {
    for (int i = 0; i < array_size/2; i++) {
        double temp = arr[i];
        arr[i] = arr[array_size - 1 -i];
        arr[array_size - 1 -i] = temp;
    }
}