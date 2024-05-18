/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：vector.h
*   Author：leekaihua
*   Date：2024年03月24日
*   Brife：
*



*/
#pragma once

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

namespace lee {
    namespace stl {
        template <typename T>
        class Vector {
            private:
                T* m_data;
                int m_size;
                int m_capacity;

                bool is_basic_type();
            public:
                Vector();
                ~Vector();
                
                void push_back(const T& value);
                void pop_back();
                int size() const;
                int capacity() const;
                void show() const;
                void reserve(int size);
                void resize(int size);
                T& at(int index);
                T& operator[](int index);
                T& front();
                T& back();
                bool empty() const;
                void clear();
                void swap(Vector<T>& other);
                T* data();
                Vector<T>& operator=(const Vector<T>& other);

                // 迭代器作为一个内部类实现
                class Iterator {
                    private:
                        // 迭代器本身是一个指针
                        T* m_pointer;
                    public:
                        Iterator() : m_pointer(nullptr) {};
                        Iterator(T* pointer) : m_pointer(pointer) {}
                        ~Iterator() {}

                        bool operator==(const Iterator& other) {
                            return m_pointer == other.m_pointer;
                        }
                        bool operator!=(const Iterator& other) {
                            return m_pointer != other.m_pointer;
                        }

                        Iterator operator=(const Iterator& other) {
                            m_pointer = other.m_pointer;
                            return *this;
                        }

                        // ++迭代器
                        Iterator& operator++() {
                            m_pointer += 1;
                            return *this;
                        }
                        // 迭代器++
                        Iterator operator++(int) {
                            Iterator it = *this;
                            // 调用上面的operator++() 函数
                            ++(*this);
                            return it;
                        }

                        Iterator operator+(int i) {
                            Iterator it = *this;
                            it.m_pointer += i;
                            return it;
                        }
                        Iterator operator-(int i) {
                            Iterator it = *this;
                            it.m_pointer -= i;
                            return it;
                        }

                        Iterator& operator+=(int i) {
                            m_pointer += i;
                            return *this;
                        }
                        Iterator& operator-=(int i) {
                            m_pointer -= i;
                            return *this;
                        }

                        int operator-(const Iterator& other) const {
                            return m_pointer - other.m_pointer;
                        }

                        T& operator*() {
                            return *m_pointer;
                        }
                        T* operator->() {
                            return m_pointer;
                        }
                };

                Iterator begin();
                Iterator end();
                Iterator find(const T& value);
                Iterator insert(const Iterator iter, const T& value);
                Iterator insert(const Iterator iter, int n, const T& value);
        };

        template <typename T>
        Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0) {

        }

        template <typename T>
        Vector<T>::~Vector() {
            if (m_data != nullptr) {
                delete [] m_data;
                m_data = nullptr;
            }
            m_size = 0;
            m_capacity = 0;
        }

        template <typename T>
        void Vector<T>::push_back(const T& value) {
            // 如果空间足够
            if (m_size < m_capacity) {
                m_data[m_size] = value;
                m_size++;
                return;
            }
            // 如果空间不够
            if (m_capacity == 0) {
                m_capacity = 1;
            } else {
                m_capacity *= 2;
            }
            T* data = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                data[i] = m_data[i];
            }
            if (m_data != nullptr) {
                delete [] m_data;
                m_data = nullptr;
            }
            m_data = data;
            m_data[m_size] = value;
            m_size++;
            return;
        }

        template <typename T>
        void Vector<T>::pop_back() {
            if (m_size > 0) {
                m_size--;
            }
        }

        template <typename T>
        int Vector<T>::size() const {
            return m_size;
        }

        template <typename T>
        int Vector<T>::capacity() const {
            return m_capacity;
        }

        // 便于测试
        template <typename T>
        void Vector<T>::show() const {
            cout << "size=" << size() << ", capacity=" << capacity() << endl;
            if (size() == 0) {
                return;
            }
            for (int i = 0; i < m_size; i++) {
                cout << m_data[i] << ", ";
            }
            cout << endl << endl;
        }

        template <typename T>
        void Vector<T>::reserve(int size) {
            if (size <= m_capacity) {
                return;
            }
            while (m_capacity < size) {
                if (m_capacity == 0) {
                    m_capacity = 1;
                } else {
                    m_capacity *= 2;
                }
            }
            T* data = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                data[i] = m_data[i];
            }
            if (m_data != nullptr) {
                delete [] m_data;
                m_data = nullptr;
            }
            m_data = data;
        }

        template <typename T>
        void Vector<T>::resize(int size) {
            if (size <= m_size) {
                m_size = size;
                return;
            }
            if (size <= m_capacity) {
                for (int i = m_size; i < size; i++) {
                    m_data[i] = T();
                }
                m_size = size;
                return;
            }
            while (m_capacity < size) {
                if (m_capacity == 0) {
                    m_capacity = 1;
                } else {
                    m_capacity *= 2;
                }
            }
            T* data = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                data[i] = m_data[i];
            }
            for (int i = m_size; i < size; i++) {
                data[i] = T();
            }
            m_size = size;
            if (m_data != nullptr) {
                delete [] m_data;
                m_data = nullptr;
            }
            m_data = data;
        }

        template <typename T>
        T& Vector<T>::at(int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("out of range, index: " + std::to_string(index));
            }
            return m_data[index];
        }

        template <typename T>
        T& Vector<T>::operator[](int index) {
            return at(index);
        }

        template <typename T>
        bool Vector<T>::empty() const {
            return m_size == 0;
        }

        template <typename T>
        void Vector<T>::clear() {
            m_size = 0;
        }

        template <typename T>
        T& Vector<T>::front() {
            return at(0);
        }

        template <typename T>
        T& Vector<T>::back() {
            return at(m_size - 1);
        }

        template <typename T>
        void Vector<T>::swap(Vector<T>& other) {
            T* data = other.m_data;
            int size = other.m_size;
            int capacity = other.m_capacity;

            other.m_data = m_data;
            other.m_size = m_size;
            other.m_capacity = m_capacity;

            m_data = data;
            m_size = size;
            m_capacity = capacity;
        }

        template <typename T>
        T* Vector<T>::data() {
            return m_data;
        }

        template <typename T>
        Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
            if (m_capacity < other.m_size) {
                if (m_data != nullptr) {
                    delete [] m_data;
                    m_data = nullptr;
                    m_size = 0;
                    m_capacity = 0;
                }
                while (m_capacity < other.m_size) {
                    if (m_capacity == 0) {
                        m_capacity = 1;
                    } else {
                        m_capacity *= 2;
                    }
                }
                m_data = new T[m_capacity];
            }
            for (int i = 0; i < other.m_size; i++) {
                m_data[i] = other.m_data[i];
            }
            m_size = other.m_size;
            return *this;
        }

        template <typename T>
        // why the beginning qualifier is typename?
        typename Vector<T>::Iterator Vector<T>::begin() {
            Vector<T>::Iterator it(m_data);
            return it;
        }

        template <typename T>
        typename Vector<T>::Iterator Vector<T>::end() {
            Vector<T>::Iterator it(m_data + m_size);
            return it;
        }

        template <typename T>
        typename Vector<T>::Iterator Vector<T>::find(const T& value) {
            for (Vector<T>::Iterator iter = begin(); iter != end(); iter++) {
                if (*iter == value) {
                    return iter;
                }
            }
            return end();
        }

        template <typename T>
        bool Vector<T>::is_basic_type() {
            // 指针类型也算是基本类型
            if (std::is_pointer<T>::value) {
                return true;
            }
            return (typeid(T) == typeid(bool) ||
                    typeid(T) == typeid(char) ||
                    typeid(T) == typeid(short) ||
                    typeid(T) == typeid(int) ||
                    typeid(T) == typeid(long) ||
                    typeid(double) == typeid(double));
        }

        template <typename T>
        typename Vector<T>::Iterator Vector<T>::insert(const Vector<T>::Iterator iter, const T& value) {
            return insert(iter, 1, value);
        }

        template <typename T>
        typename Vector<T>::Iterator Vector<T>::insert(const Vector<T>::Iterator iter, int n, const T& value) {
            int size = iter - begin();
            if (m_size + n <= m_capacity) {
                // bool 类型的插入性能非常低，针对性优化
                if (is_basic_type()) {
                    std::memmove(m_data + size + n, m_data + size, (m_size - size) * sizeof(T));
                } else {
                    for (int i = m_size; i > size; i--) {
                        m_data[i + n - 1] = m_data[i - 1];
                    }
                }
                for (int i = 0; i < n; i++) {
                    m_data[size + i] = value;
                }
                m_size += n;
                return Vector<T>::Iterator(m_data + size);
            }
            while (m_size + n > m_capacity) {
                if (m_capacity == 0) {
                    m_capacity = 1;
                } else {
                    m_capacity *= 2;
                }
            }
            T* data = new T[m_capacity];
            for (int i = 0; i < size; i++) {
                data[i] = m_data[i];
            }
            for (int i = 0; i < n; i++) {
                data[size + i] = value;
            }
            for (int i = size; i < m_size; i++) {
                data[i] = m_data[i];
            }
            if (m_data != nullptr) {
                delete [] m_data;
                m_data = nullptr;
            }
            m_data = data;
            m_size += n;
            return Vector<T>::Iterator(m_data + size);
        }
    }
}