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

#include "lee/exception/my_exception.h"
using lee::exception::out_of_vector_range;
#include "allocator.h"
using lee::stl::Allocator;

namespace lee {
namespace stl {

template <typename T, typename Alloc = Allocator<T>>
class vector {
public:
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
    void push_back(T item);
    void pop_back();
    // append_range();

    // insert();
    // insert_range();
    // erase();
    // swap();
    // clear();

    // resize();
    // reserve();
    // shrink_to_fit();
private:
    T* _first;
    T* _last;
    T* _end;
    Alloc _allocator;

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
void vector<T, Alloc>::push_back(T item) {
    if (full()) {
        expand_space();
    }
    *_last = item;
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

}
}