/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p3.cpp
*   Author：leekaihua
*   Date：2023年03月21日
*   Brife：
*



*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    using std::cout;
    using std::endl;
    using std::cerr;
    using std::ifstream;
    using std::ofstream;

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " source_file dest_file" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin.is_open()) {
        cerr << "Could not open file: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    if (!fout.is_open()) {
        cerr << "Could not open file: " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    
    char ch;
    while(fin.get(ch)) {
        fout.put(ch);
    }
    if (fin.eof()) {
        cout << "Terminated because of EOF." << endl;
    } else if (fin.fail()) {
        cout << "Terminated because of data mismatch or stream broken." << endl;
    } else {
        cout << "Terminated because of unknown reason." << endl;
    }

    cout << "Done!" << endl;
    return 0;
}