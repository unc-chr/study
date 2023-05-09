/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：AB8.cpp
*   Author：leekaihua
*   Date：2023年04月29日
*   Brife：
*



*/

#include <iostream>
using namespace std;

class queue_self {
    private:
        int capacity;
        int* room;
        int head;
        int tail;
    public:
        queue_self(int capacity) {
            this->capacity = capacity;
            room = new int[capacity];
            head = 0;
            tail = 0;
        }

        bool push(int x) {
            if (tail - head == capacity) {
                return false;
            }
            *(room + tail % capacity) = x;
            tail++;
            return true;
        }

        int front() {
            if (tail == head) {
                return -1;
            }
            return *(room + head % capacity);
        }

        int pop() {
            if (tail == head) {
                return -1;
            }
            head++;
            cout << "head: " << head << endl;
            cout << "offset: " << (head - 1) % capacity << endl;
            cout << "room: " << room << endl;
            cout << "*room: " << *room << endl;
            cout << "room offset: " << (room + (head - 1) % capacity) << endl;
            cout << "*room offset: " << *(room + (head - 1) % capacity) << endl;
            return *(room + (head - 1) % capacity);
        }

        void traverse() {
            cout << "traverse: ";
            for (int i = 0; i < capacity; i++) {
                cout << *(room + i) << " ";
            }
            cout << endl;
        }

        ~queue_self() {
            delete room;
        }

};

int main() {
    int capacity;
    int num_order;
    cin >> capacity;
    cin >> num_order;
    queue_self instance(capacity);
    while (cin.get() != '\n') {
        continue;
    }

    string input;
    int result;
    while (true) {
        getline(cin, input);
        if (input == "") {
            break;
        }
        if (input.find(' ') == string::npos) {
            if (input == "front") {
                result = instance.front();
            } else {
                result = instance.pop();
            }
            if (result == -1) {
                cout << "empty" << endl;
            } else {
                cout << result << endl;
            }
        } else {
            int param = stoi(input.substr(input.find(' ')));
            bool res = instance.push(param);
            if (!res) {
                cout << "full" << endl;
            }
        }
        cout << "input: " << input << endl;
        instance.traverse();
        cout << endl;
    }
}