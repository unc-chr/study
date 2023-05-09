/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：queuetp.h
*   Author：leekaihua
*   Date：2023年03月23日
*   Brife：
*



*/
#pragma once

template <typename T>
class QueueTp {
    private:
        struct Node {
            T item;
            Node* next;
        };
        enum {Q_SIZE = 10};
        Node* front;
        Node* rear;
        int items;
        const int qsize;
        QueueTp(const QueueTp& q) : qsize(0) {}
        QueueTp& operator=(const QueueTp& q) {return *this;}
    public:
        QueueTp(int qs = Q_SIZE);
        ~QueueTp();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const T& item);
        bool dequeue(T& item);
};

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

template <typename T>
QueueTp<T>::~QueueTp() {
    Node* temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}


template <typename T>
bool QueueTp<T>::isempty() const {
    return items == 0;
}

template <typename T>
bool QueueTp<T>::isfull() const {
    return items == qsize;
}

template <typename T>
int QueueTp<T>::queuecount() const {
    return items;
}

template <typename T>
bool QueueTp<T>::enqueue(const T& item) {
    if (isfull()) {
        return false;
    }
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr) {
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T& item) {
    if (front == nullptr) {
        return false;
    }
    item = front->item;
    items--;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (items == 0) {
        rear = nullptr;
    }
    return true;
}