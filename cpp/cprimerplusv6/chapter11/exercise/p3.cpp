/*================================================================
*   Copyright (C) 2022 Goldman Ltd. All rights reserved.
*   
*   File：randwalk.cpp
*   Author：leekaihua
*   Date：2022年01月02日
*   Brife：
*



*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

void show_result (unsigned long* steps_array, unsigned int N);
int main() {
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "How many times do you want to try: ";
    unsigned int N;
    cin >> N;
    unsigned long* steps_array = new unsigned long [N];


    cout << "Enter  target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        for (int i = 0; i < N; i++) {
            while (result.magval() < target) {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
            cout << result << endl;
            result.polar_mode();
            cout << " or\n" << result << endl;
            cout << "Average outward distance per step = "
                << result.magval()/steps << endl;
            steps_array[i] = steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        show_result(steps_array, N);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }

    return 0;
}

void show_result (unsigned long* steps_array, unsigned int N) {
    unsigned long max_step = steps_array[0];
    unsigned long min_step = steps_array[0];
    unsigned long sum = 0;
    for (int i = 1; i < N; i++) {
        if (steps_array[i] > max_step) {
            max_step = steps_array[i];
        }
        if (steps_array[i] < min_step) {
            min_step = steps_array[i];
        }
        sum += steps_array[i];
    }
    double average_steps = double(sum) / N;

    std::cout << "Max step = " << max_step << std::endl;
    std::cout << "Min step = " << min_step << std::endl;
    std::cout << "Average step = " << average_steps << std::endl;
}