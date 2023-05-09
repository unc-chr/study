/*================================================================
*   Copyright (C) 2021 Goldman Ltd. All rights reserved.
*   
*   File：floatnum.cpp
*   Author：leekaihua
*   Date：2021年12月05日
*   Brife：
*



*/

#include <iostream>
#include <cfloat>

int main(){
    using namespace std;

    // print cfloat info
    // cout << "double significant digits " << DEL_DIG;
    cout << "float significant digits " << FLT_DIG << endl;
    cout << "long double significant digits " << LDBL_DIG << endl;

    // cout << "double mantissa digits " << DEL_MANT_DIG;
    cout << "float mantissa digits " << FLT_MANT_DIG << endl;
    cout << "long double mantissa digits " << LDBL_MANT_DIG << endl;


    float tub = 10.0/3.0;
    double mint = 10.0/3.0;
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs" << million * tub;

    cout << ", \nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "now is fixed point print" << endl;
    cout << "tub = " << tub;
    cout << ", a million tubs" << million * tub;

    cout << ", \nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;

    return 0;
}