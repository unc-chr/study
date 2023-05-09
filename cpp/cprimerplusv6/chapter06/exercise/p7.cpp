/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：p7.cpp
*   Author：leekaihua
*   Date：2023年03月05日
*   Brife：
*



*/

#include <iostream>
#include <string>
#include <cctype>

bool is_start_with_alpha(std::string);
bool is_start_with_vowel(std::string);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter words (q to quit): " << endl;
    std::string word;
    int num_vowel = 0;
    int num_consonant = 0;
    int num_others = 0;
    while (cin >> word) {
        if (word == "q") {
            break;
        }
        if (!is_start_with_alpha(word)) {
            num_others++;
            continue;
        }
        if (is_start_with_vowel(word)) {
            num_vowel++;
        } else {
            num_consonant++;
        }
    }

    cout << "-------------------" << endl;
    cout << "Now print the statis result: " << endl;
    cout << num_vowel << " words beginning with vowels" << endl;
    cout << num_consonant << " words beginning with consonants" << endl;
    cout << num_others << " others" << endl;
}

bool is_start_with_alpha(std::string word) {
    return isalpha(word[0]);
}

bool is_start_with_vowel(std::string word) {
    char first = word[0];
    switch (first)
    {
    case 'a':
        return true;
    case 'e':
        return true;
    case 'i':
        return true;
    case 'o':
        return true;
    case 'u':
        return true;
    default:
        return false;
    }
}
