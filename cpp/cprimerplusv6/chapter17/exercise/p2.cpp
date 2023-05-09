/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p2.cpp
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
    using std::cerr;
    using std::cin;
    using std::endl;
    using std::ofstream;

    if (argc == 1) {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        exit(EXIT_FAILURE);
    }
    
    ofstream fout(argv[1]);
    if (!fout.is_open()) {
        cerr << "Could not open " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    char ch;
    while (cin.get(ch)) {
        fout << ch;
    }
    if (cin.eof()) {
        cout << "Teriminated because of EOF" << endl;
    } else if (cin.fail()) {
        cout << "Teriminated because of data mismatch or stream broken" << endl;
    } else {
        cout << "Terminated because of unknown reasons." << endl;
    }

    fout.close();
    cout << "Done!" << endl;
    return 0;
}