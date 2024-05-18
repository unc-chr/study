/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
*   Author：leekaihua
*   Date：2023年03月22日
*   Brife：
*



*/
#include "cpmv.h"
#include <iostream>
#include <utility>

int main() {
    using namespace std;

    {
        cout << "ins1: " << endl;
        Cpmv ins1;
        ins1.Display();

        cout << "ins2: " << endl;
        Cpmv ins2("q11111", "z11111");
        ins2.Display();

        cout << "ins3: " << endl;
        Cpmv ins3("q22222", "z22222");
        ins3.Display();

        cout << "ins4: " << endl;
        Cpmv ins4(ins2);
        ins4.Display();

        cout << "ins5: " << endl;
        Cpmv ins5(ins2 + ins3);
        ins5.Display();
        
        cout << "ins6: " << endl;
        Cpmv ins6 = std::move(ins4);
        ins6.Display();

        cout << "ins5: " << endl;
        ins5 = ins2;
        ins5.Display();

        cout << "ins5: " << endl;
        ins5 = ins2 + ins3;
        ins5.Display();
    }

    cout << "Done!" << endl;

    return 0;
}