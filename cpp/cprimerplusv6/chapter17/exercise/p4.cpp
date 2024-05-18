/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p4.cpp
*   Author：leekaihua
*   Date：2023年03月21日
*   Brife：
*



*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    using std::cout;
    using std::endl;
    using std::cerr;
    using std::string;
    using std::ifstream;
    using std::ofstream;

    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " source_file1 source_file2 dest_file" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream fin1(argv[1]);
    ifstream fin2(argv[2]);
    ofstream fout(argv[3]);
    if (!fin1.is_open()) {
        cerr << "Could not open file: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fin2.is_open()) {
        cerr << "Could not open file: " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open()) {
        cerr << "Could not open file: " << argv[3] << endl;
        exit(EXIT_FAILURE);
    }
    
    string str1;
    string str2;
    int counter = 0;
    int file1_row = 0;
    int file2_row = 0;
    int len1;
    int len2;
    cout << "file1_row: " << file1_row << endl;
    getline(fin1, str1);
    getline(fin2, str2);
    while(fin1.good() || fin2.good()) {
        len1 = str1.size();
        len2 = str2.size();
        if (len1 > 0) {
            file1_row++;
        }
        if (len2 > 0) {
            file2_row++;
        }
        if (len2 > len1) {
            fout << str2 << " " << str1 << endl;
        } else {
            fout << str1 << " " << str2 << endl;
        }
        counter++;
        cout << "counter: " << counter << ", file1 row: " << file1_row
            << ", file2_row: " << file2_row << endl;
        getline(fin1, str1);
        getline(fin2, str2);
    }
    if (fin1.eof()) {
        cout << argv[1] << " Terminated because of EOF." << endl;
    } else if (fin1.fail()) {
        cout << argv[1] << " Terminated because of data mismatch or stream broken." << endl;
    } else {
        cout << argv[1] << " Terminated because of unknown reason." << endl;
    }

    if (fin2.eof()) {
        cout << argv[2] << " Terminated because of EOF." << endl;
    } else if (fin2.fail()) {
        cout << argv[2] << " Terminated because of data mismatch or stream broken." << endl;
    } else {
        cout << argv[2] << " Terminated because of unknown reason." << endl;
    }

    cout << "Done!" << endl;
    return 0;
}