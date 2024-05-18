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
double ave_array(const double arr[], int array_size);

int main(){
    const int LIMIT = 10;
    double score[10];
    int array_size = fill_array(score, LIMIT);
    show_array(score, array_size);
    double ave_score = ave_array(score, array_size);
    cout << "Average score is: " << ave_score << endl;
    cout << "Done!" << endl;

    return 0;
}

int fill_array(double arr[], int limit) {
    double temp_score;
    int i = 0;
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
        cout << "score " << i + 1 << ": " << arr[i] << endl;
    }
}

double ave_array(const double arr[], int array_size) {
    double sum_score;
    for (int i = 0; i < array_size; i++) {
        sum_score += arr[i];
    }
    double ave_score = sum_score/array_size;
    return ave_score;
}