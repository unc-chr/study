/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月06日
*   Brife：
*



*/

#include <iostream>

const int Max = 5;

double * fill_array(double* ar1, double* ar2);
void show_array(const double* ar1, const double* ar2);
void revalue(double r, double* ar1, const double* ar2);

int main() {
    using namespace std;
    double properties[Max];

    const double* end = fill_array(properties, properties + Max);
    show_array(properties, end);
    if (properties != end) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }

    cout << "Done.\n";

    return 0;
}

double* fill_array(double* ar1, double* ar2) {
    using namespace std;
    double temp;
    double* end = ar1;
    for (int i = 0; end < ar2; end++, i++) {
        cout << "Enter value #: " << (i + 1) << ": ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        } else if (temp < 0) {
            break;
        }
        *end = temp;
    }

    return end;
}

void show_array(const double* ar1, const double* ar2) {
    using namespace std;
    for (int i = 0; ar1 < ar2; i++, ar1++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << *ar1 << endl;
    }
}

void revalue(double r, double* ar1, const double* ar2) {
    for (; ar1 < ar2; ar1 ++) {
        *ar1 *= r;
    }
}