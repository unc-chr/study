/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vector.h
*   Author：leekaihua
*   Date：20240630
*   Brife：
*
*   reference: https://en.cppreference.com/w/cpp/container/vector
*/

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

#include "lee/exception/my_exception.h"
using lee::exception::out_of_vector_range;
#include "allocator.h"
using lee::stl::Allocator;

namespace lee {
namespace stl {

template <typename T, typename Alloc = Allocator<T>>
class vector {
public:
    class iterator {
    public:
        // friend class, that mean iterator can access to vector's member
        friend class vector<T, Alloc>;
        iterator(vector<T, Alloc>* p_vec, T* p_T);
        ~iterator() = default;
        iterator(const iterator& other);
        iterator& operator++();
        iterator operator++(int);
        iterator operator+(int);
        bool operator!=(const iterator& other);
        bool operator<(const iterator& other);
        bool operator<=(const iterator& other);
        bool operator>=(const iterator& other);
        bool operator>(const iterator& other);
        T& operator*() const;
    private:
        T* _p_T;
        // pointer to owner container
        vector<T, Alloc>* _p_vec;
    };

    struct iterator_base {
        iterator* _p_iter;
        iterator_base* _next;

        iterator_base(iterator* p_iter = nullptr, iterator_base* next = nullptr);
        ~iterator_base();
    };

    vector(int size = 4, const Alloc& alloc = Allocator<T>());
    vector(const vector<T, Alloc>& other);
    vector<T, Alloc>& operator=(const vector<T, Alloc>& other);
    ~vector();
    
    // assign();
    // assign_range();
    // get_allocator();
    // data();

    size_t size() const;
    bool empty() const;
    bool full() const;
    // capacity();
    // max_size();

    T& front() const;
    T& back() const;
    T& at(size_t pos) const;
    T& operator[](size_t pos) const;

    // emplace();
    // emplace_back();
    void push_back(const T& item);
    void pop_back();
    // append_range();

    // insert();
    // insert_range();
    iterator erase(iterator iter);
    // swap();
    // clear();

    // resize();
    // reserve();
    // shrink_to_fit();

    iterator begin();
    iterator end();
    void verify(T* begin, T* end);
private:
    T* _first;
    T* _last;
    T* _end;
    Alloc _allocator;
    // dummy head of iterator_base list, this list stores all iterator
    // created in container, so all invalid iterator will be set to not
    // available
    iterator_base _head;

    void expand_space();
};

}
}


namespace lee {
namespace stl {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(int size, const Alloc& alloc)
        : _allocator(alloc) {
    _first = _allocator.allocate(size);
    _last = _first;
    _end = _first + size;
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const vector<T, Alloc>& other) {
    int capacity = other._end - other._first;
    int size = other._last - other._first;
    _first = _allocator.allocate(capacity);
    for (int i = 0; i < size; i++) {
        _allocator.construct(_first + i, other._first[i]);
    }
    _last = _first + size;
    _end = _first + capacity;
}

template <typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T, Alloc>& other) {
    if (this == &other) {
        return *this;
    }
    for (T* p = _first; p != _last; p++) {
        _allocator.destroy(p);
    }
    _allocator.deallocate(_first);
    int capacity = other._end - other._first;
    int size = other._last - other._first;
    _first = _allocator.allocate(capacity);
    for (int i = 0; i < size; i++) {
        _allocator.construct(_first + i, *(other._first + i));
    }
    _last = _first + size;
    _end = _first + capacity;

    return *this;
}

template <typename T, typename Alloc>
vector<T, Alloc>::~vector() {
    // delete list start with _head
    iterator_base* curr = _head._next;
    iterator_base* temp = nullptr;
    while (curr) {
        temp = curr;
        curr = curr->_next;
        delete temp;
    }

    // destroy T data and free memory
    for (T* p = _first; p != _last; p++) {
        _allocator.destroy(p);
    }
    _allocator.deallocate(_first);
    _first = _last = _end = nullptr;
}

template <typename T, typename Alloc>
size_t vector<T, Alloc>::size() const {
    return _last - _first;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::empty() const {
    if (_last == _first) {
        return true;
    }
    return false;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::full() const {
    if (_last == _end) {
        return true;
    }
    return false;
}

template <typename T, typename Alloc>
T& vector<T, Alloc>::front() const {
    if (empty()) {
        throw "vector is empry";
    }
    return *_first;
}

template <typename T, typename Alloc>
T& vector<T, Alloc>::back() const {
    if (empty()) {
        throw "vector is empry";
    }
    return *(_last - 1);
}

template <typename T, typename Alloc>
T& vector<T, Alloc>::at(size_t pos) const {
    if (pos >= size_t(_last - _first)) {
        throw out_of_vector_range(pos, _last - _first);
    }
    return *(_first + pos);
}

template <typename T, typename Alloc>
T& vector<T, Alloc>::operator[](size_t pos) const {
    if (pos >= size_t(_last - _first)) {
        throw out_of_vector_range(pos, _last - _first);
    }
    return *(_first + pos);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(const T& item) {
    if (full()) {
        expand_space();
    }
    _allocator.construct(_last, item);
    _last++;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::pop_back() {
    if (empty()) {
        return;
    }
    _last--;
    _allocator.destroy(_last);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(vector<T, Alloc>::iterator iter) {
    // iter not in legal range
    if (iter < begin() || iter >= end()) {
        throw std::out_of_range("erase argu is out of range.");
    }
    verify(iter._p_T, _last);
    T* ptr = iter._p_T;
    _allocator.destroy(ptr);
    for (; ptr != _last - 1; ptr++) {
        *(ptr)  = *(ptr + 1);
    }
    _last--;
    return iterator(this, iter._p_T);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::expand_space() {
    int cap = _end - _first;
    T* data = _allocator.allocate(2 * cap);
    for (int i = 0; i < cap; i++) {
        _allocator.construct(data + i, *(_first + i));
    }
    for (T* p = _first; p != _end; p++) {
        _allocator.destroy(p);
    }
    _allocator.deallocate(_first);
    _first = data;
    _last = _first + cap;
    _end = _first + 2 * cap;
    std::cout << "vector expand from " << cap << " to " << 2 * cap << "." << std::endl;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::verify(T* begin, T* end) {
    iterator_base* pre = &_head;
    iterator_base* curr = _head._next;
    while (curr != nullptr) {
        if (curr->_p_iter->_p_T >= begin && curr->_p_iter->_p_T <= end) {
            curr->_p_iter->_p_vec = nullptr;
            pre->_next = curr->_next;
            delete curr;
            curr = pre->_next;
        } else {
            pre = curr;
            curr = curr->_next;
        }
    }
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() {
    return iterator(this, _first);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end() {
    return iterator(this, _last);
}

template <typename T, typename Alloc>
vector<T, Alloc>::iterator::iterator(vector<T, Alloc>* p_vec, T* p_T)
        : _p_T(p_T)
        , _p_vec(p_vec) {
    iterator_base* temp = new iterator_base(this, _p_vec->_head._next);
    _p_vec->_head._next = temp;
}

// copy constructor
template <typename T, typename Alloc>
vector<T, Alloc>::iterator::iterator(const vector<T, Alloc>::iterator& other) {
    _p_T = other._p_T;
    _p_vec = other._p_vec;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator& vector<T, Alloc>::iterator::operator++() {
    if (_p_vec == nullptr) {
        throw "iterator invalid: owner is nullptr!";
    }
    ++_p_T;
    return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator++(int) {
    if (_p_vec == nullptr) {
        throw "iterator invalid: owner is nullptr!";
    }
    return iterator(this->_p_vec, _p_T++);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator+(int range) {
    return iterator(this->_p_vec, _p_T + range);
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::iterator::operator!=(const vector<T, Alloc>::iterator& other) {
    if (_p_vec == nullptr) {
        throw "iterator's owner is nullptr!";
    }
    if (_p_vec != other._p_vec) {
        throw "iterator imcompatable!";
    }
    return _p_T != other._p_T;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::iterator::operator<(const vector<T, Alloc>::iterator& other) {
    if (_p_vec == nullptr) {
        throw "iterator's owner is nullptr!";
    }
    if (_p_vec != other._p_vec) {
        throw "iterator imcompatable!";
    }
    return _p_T < other._p_T;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::iterator::operator<=(const vector<T, Alloc>::iterator& other) {
    if (_p_vec == nullptr) {
        throw "iterator's owner is nullptr!";
    }
    if (_p_vec != other._p_vec) {
        throw "iterator imcompatable!";
    }
    return _p_T <= other._p_T;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::iterator::operator>(const vector<T, Alloc>::iterator& other) {
    if (_p_vec == nullptr) {
        throw "iterator's owner is nullptr!";
    }
    if (_p_vec != other._p_vec) {
        throw "iterator imcompatable!";
    }
    return _p_T > other._p_T;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::iterator::operator>=(const vector<T, Alloc>::iterator& other) {
    if (_p_vec == nullptr) {
        throw "iterator's owner is nullptr!";
    }
    if (_p_vec != other._p_vec) {
        throw "iterator imcompatable!";
    }
    return _p_T >= other._p_T;
}

template <typename T, typename Alloc>
T& vector<T, Alloc>::iterator::operator*() const {
    if (_p_vec == nullptr) {
        throw "iterator invalid: owner is nullptr!";
    }
    return *_p_T;
}

template <typename T, typename Alloc>
vector<T, Alloc>::iterator_base::iterator_base(
        vector<T, Alloc>::iterator* p_iter, 
        vector<T, Alloc>::iterator_base* next)
        : _p_iter(p_iter)
        , _next(next) {
    
}

template <typename T, typename Alloc>
vector<T, Alloc>::iterator_base::~iterator_base() {
    _p_iter = nullptr;
    _next = nullptr;
}

}
}