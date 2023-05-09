/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：vect3.cpp
*   Author：leekaihua
*   Date：2023年03月20日
*   Brife： 《C++ primer plus》程序清单16.9
*

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool FillReview(Review& rr);
void ShowReview(const std::shared_ptr<Review> rr);

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool compare_rating(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool compare_price(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);

void show_original(std::vector<std::shared_ptr<Review>> books);
void show_alpha_order(std::vector<std::shared_ptr<Review>> books);
void show_ratting_up(std::vector<std::shared_ptr<Review>> books);
void show_ratting_down(std::vector<std::shared_ptr<Review>> books);
void show_price_up(std::vector<std::shared_ptr<Review>> books);
void show_price_down(std::vector<std::shared_ptr<Review>> books);

enum show_style {ORIGINAL, ALPAH_ORDER, RATING_UP, RATING_DOWN, PRICE_UP, PRICE_DOWN};

int main() {
    using namespace std;

    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp)) {
        std::shared_ptr<Review> ps(new Review(temp));
        books.push_back(ps);
    }
    if (books.size() > 0) {
        cout << "Enter the show style you want, 0 for original, 1 for alpha"
            " 2 for ratting up, 3 for ratting down, 4 for price_up, 5 for price down: ";
        int show_style;
        while (cin >> show_style) {
            switch (show_style) {
                case ORIGINAL:
                    show_original(books);
                    break;
                case ALPAH_ORDER:
                    show_alpha_order(books);
                    break;
                case RATING_UP:
                    show_ratting_up(books);
                    break;
                case RATING_DOWN:
                    show_ratting_down(books);
                    break;
                case PRICE_UP:
                    show_price_up(books);
                    break;
                case PRICE_DOWN:
                    show_price_down(books);
                    break;
                default:
                    cout << "Sorry, your input wrong! ";
                    break;
            }
            cout << "Enter the show style you want again: ";
        }
    } else {
        cout << "No entries. ";
    }

    cout << "Bye." << endl;

    return 0;
}


// 从输入中读取书的信息
bool FillReview(Review& rr) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit") {
        return false;
    }

    std::cout << "Enter book rating:";
    std::cin >> rr.rating;
    if (!std::cin) {
        return false;
    }

    std::cout << "Enter book price:";
    std::cin >> rr.price;
    if (!std::cin) {
        return false;
    }

    while (std::cin.get() != '\n') {
        continue;
    }

    return true;
}

// 一元函数，给 for_each 调用
void ShowReview(const std::shared_ptr<Review> rr) {
    std::cout << rr->title << "\t" << rr->rating << "\t" << rr->price <<  std::endl;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->title < r2->title) {
        return true;
    } else if (r1->title == r2->title && r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

bool compare_rating(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

bool compare_price(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}
void show_original(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    for_each(books.begin(), books.end(), ShowReview);
}

// 默认调用 operator<，进行 title 的字母排序
void show_alpha_order(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    sort(books.begin(), books.end());
    for_each(books.begin(), books.end(), ShowReview);
}

void show_ratting_up(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    sort(books.begin(), books.end(), compare_rating);
    for_each(books.begin(), books.end(), ShowReview);
}

void show_ratting_down(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    sort(books.rbegin(), books.rend(), compare_rating);
    for_each(books.begin(), books.end(), ShowReview);
}

void show_price_up(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    sort(books.begin(), books.end(), compare_price);
    for_each(books.begin(), books.end(), ShowReview);
}

void show_price_down(std::vector<std::shared_ptr<Review>> books) {
    std::cout << "title" << "\t" << "rating" << "\t" << "price" << std::endl;
    sort(books.rbegin(), books.rend(), compare_price);
    for_each(books.begin(), books.end(), ShowReview);
}