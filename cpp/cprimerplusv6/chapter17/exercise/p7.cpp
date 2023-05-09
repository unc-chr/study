/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月21日
*   Brife：
*



*/

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Store {
    private:
        std::ofstream& os;
    public:
        Store(std::ofstream& m_fout) : os(m_fout) {}
        void operator()(const std::string& s) {
            std::size_t len = s.size();
            os.write((char*)&len, sizeof(std::size_t));
            os.write(s.data(), len);
        }
};

void GetStrs(std::ifstream& fin, std::vector<std::string>& vistr);
void ShowStr(const std::string& str);

int main() {
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):" << endl;
    while (getline(cin, temp) && temp[0] != '\0') {
        vostr.push_back(temp);
    }
    cout << "Here is your input." << endl;
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input." << endl;
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << endl << "Here are the strings read from the file:" << endl;
    for_each(vistr.begin(), vistr.end(), ShowStr);

    cout << "Done!" << endl;
    return 0;
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& vistr) {
    std::size_t len_size;
    while(fin.read((char*)&len_size, sizeof(std::size_t))) {
        char temp[len_size + 1];
        for (std::size_t i = 0; i < len_size; i++) {
            fin.read(&temp[i], 1);
        }
        temp[len_size] = '\0';
        vistr.push_back(std::string(temp));
    }
}

void ShowStr(const std::string& str) {
    std::cout << str << std::endl;
}