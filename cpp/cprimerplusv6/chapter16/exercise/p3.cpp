/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：hangman.cpp
*   Author：leekaihua
*   Date：2023年03月18日
*   Brife：
*



*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>


int main() {
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    using std::string;

    std::vector<std::string> wordlist;
    std::ifstream in_file;
    std::string filename;
    std::cout << "Enter the file name including string list: ";
    std::cin >> filename;
    const char* filename_read = filename.c_str();
    in_file.open(filename_read);
    std::string temp;
    while (in_file >> temp) {
        wordlist.push_back(temp);
    }
    if (in_file.eof()) {
        std::cout << "End of file reached." << endl;
    } else if (in_file.fail()) {
        cout << "Input terminated by date mismatch." << endl;
    } else {
        cout << "Input terminated for unknown reasons." << endl;
    }
    in_file.close();

    int num_of_word = wordlist.size();
    if (num_of_word == 0) {
        cout << "No words read from your file: " << filename << endl;
        cout << "Maybe you input wrong file!!!" << endl;
        // 这个 0，用于表示程序不是因为异常退出，而是因为交互内容错误。程序运行没有问题。
        exit(0);
    }
   
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n>: ";
    cin >> play;
    play = tolower(play);
    while (play == 'y') {
        string target = wordlist[std::rand() % num_of_word];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my sercet word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";

        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target) {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                cout << "You already guessed that. Try again." << endl;
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos) {
                cout << "Oh, bad guess!" << endl;
                --guesses;
                badchars += letter;
            } else {
                cout << "Good guess!" << endl;
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if (attempt != target) {
                if (badchars.length() > 0) {
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guesses << " bad guesses left." << endl;
            }
            cout << endl;
        }
        if (guesses > 0) {
            cout << "That's right!" << endl;
        } else {
            cout << "Sorry, the word is " <<  target << "." << endl;
        }

        cout << "Will you play another? <y/n> :";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye!" << endl;

    return 0;
}