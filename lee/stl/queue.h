/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：queue.h
*   Author：mayi
*   Date：20240703
*   Brife：
*



*/
#pragma once

#include <cstdlib>

#include "lee/exception/my_exception.h"
using lee::exception::empty_container;

namespace lee {
namespace stl {

template <typename T>
class queue {
public:
    queue();
    ~queue();
    void push(T item);
    void pop();
    T& front();
    T& back();
    void clear_pool();
private:
    struct node {
        T _data;
        node* _pre;
        node* _next;
        static const int _OBJ_POOL_SIZE;
        static node* _pool_mem;

        node(T data = T(), node* pre = nullptr, node* next = nullptr);
        ~node();

        void* operator new(size_t size);
        void operator delete(void* p);

    };

    node* _front;
    node* _rear;
};

}
}

namespace lee {
namespace stl {

template <typename T>
queue<T>::queue() {
    _front = new node();
    _rear = new node();
    _front->_next = _rear;
    _rear->_pre = _front;
}

template <typename T>
queue<T>::~queue() {
    node* curr = _front->_next;
    node* temp = nullptr;
    while (curr != _rear) {
        temp = curr;
        curr = curr->_next;
        delete temp;
    }
    delete _rear;
    delete _front;
    _front = _rear = nullptr;
    clear_pool();
}

template <typename T>
void queue<T>::push(T item) {
    node* pre = _rear->_pre;
    node* temp = new node(item, pre, _rear);
    pre->_next = temp;
    _rear->_pre = temp;
}

template <typename T>
void queue<T>::pop() {
    if (_front->_next == _rear) {
        throw empty_container("empty queue, pop failed!");
    }
    node* temp = _front->_next;
    _front->_next = temp->_next;
    temp->_next->_pre = temp->_pre;
    delete temp;
}

template <typename T>
T& queue<T>::front() {
    if (_front->_next == _rear) {
        throw empty_container("empty queue, front failed!");
    }
    return _front->_next->_data;
}

template <typename T>
T& queue<T>::back() {
    if (_front->_next == _rear) {
        throw empty_container("empty queue, get back failed!");
    }
    return _rear->_pre->_data;
}

template <typename T>
const int queue<T>::node::_OBJ_POOL_SIZE = 10000;

template <typename T>
typename queue<T>::node* queue<T>::node::_pool_mem = nullptr;

template <typename T>
queue<T>::node::node(T data, node* pre, node* next)
        : _data(data)
        , _pre(pre)
        , _next(next) {
}

template <typename T>
queue<T>::node::~node() {
    _pre = nullptr;
    _next = nullptr;
}

template <typename T>
void* queue<T>::node::operator new(size_t size) {
    if (_pool_mem == nullptr) {
        _pool_mem = (node*)malloc(sizeof(node) * _OBJ_POOL_SIZE);
        // _pool_mem = (node*)new char[_OBJ_POOL_SIZE * sizeof(node)];
        node* p = _pool_mem;
        for (; p < _pool_mem + _OBJ_POOL_SIZE - 1; ++p) {
            p->_next = p + 1;
        }
        p->_next = nullptr;
    }
    node* res = _pool_mem;
    _pool_mem = _pool_mem->_next;
    return res;
}

template <typename T>
void queue<T>::node::operator delete(void* p) {
    node* del = (node*)p;
    del->_next = _pool_mem;
    _pool_mem = del;
}

template <typename T>
void queue<T>::clear_pool() {
    free(node::_pool_mem);
}

}
}