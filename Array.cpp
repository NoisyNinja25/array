#include "Array.h"
#include <iostream>

Array::Array() {
    m_cur_size = 0;
    m_max_size = 0;

    m_data = nullptr;
}

Array::Array(unsigned int length) {
    m_cur_size = length;
    m_max_size = length;
    
    m_data = new char[length];
}

Array::Array(unsigned int length, char fill) {
    m_cur_size = length;
    m_max_size = length;

    m_data = new char[length];
    for (int i = 0; i < length; i++) {
        m_data[i] = fill;
    }
}

Array::Array(const Array & arr) {
    m_cur_size = arr.get_size();
    m_max_size = arr.get_max_size();
    m_data = new char[m_cur_size];

    for (int i = 0; i < m_cur_size; i++) {
        m_data[i] = arr.get_element(i);
    }
}

Array::~Array() {
   delete [] m_data;
}

unsigned int Array::get_size() const {
    return m_cur_size;
}

unsigned int Array::get_max_size() const {
    return m_max_size;
}

void Array::set_element(unsigned int index, char el) {
    m_data[index] = el;
}

char Array::get_element(unsigned int index) const {
    return m_data[index];
}

void Array::resize(unsigned int length) {
    if (length > m_max_size) {
        reallocate_(length);
    } else {
        m_cur_size = length;
    }
}

void Array::shrink() {
    reallocate_(m_cur_size);
}

int Array::find(char target) const {
    for (int i = 0; i < m_cur_size; i++) {
        if (m_data[i] == target) {
            return i;
        }
    }
    return -1;
}



void Array::fill(char el) {
    for (int i = 0; i < m_cur_size; i++) {
        m_data[i] = el;
    }
}

void Array::reverse() {
    unsigned int head = 0;
    unsigned int mid = m_cur_size / 2;
    unsigned int tail = m_cur_size - 1;

    while (head < mid) {
        char temp = m_data[tail];
        m_data[tail] = m_data[head];
        m_data[head] = temp;

        head++;
        tail--;
    }
}

Array Array::slice(unsigned int begin) const {
    return slice(begin, m_cur_size);
}

Array Array::slice(unsigned int begin, unsigned int end) const {
    unsigned int length = end - begin;
    Array arr = Array(length);

    for (int i = 0; i < length; i++) {
        char el = m_data[begin + i];
        arr.set_element(i, el);
    } 

    return arr;
}

char & Array::operator [] (unsigned int index) {
    return m_data[index];
}

const char & Array::operator [] (unsigned int index) const {
    return m_data[index];
}

const Array Array::operator = (const Array & rhs) {
    m_cur_size = rhs.get_size();
    m_max_size = rhs.get_max_size();

    delete [] m_data;
    m_data = new char[m_cur_size];

    for (int i = 0; i < m_cur_size; i++) {
        m_data[i] = rhs.get_element(i);
    }

    return *this;
}

bool Array::operator == (const Array & rhs) const {
    if (&rhs == this) {
        return true;
    }

    if (m_cur_size == rhs.get_size()) {
        for (int i = 0; i < m_cur_size; i++) {
            if (m_data[i] != rhs.get_element(i)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Array::operator != (const Array & rhs) const {
    return !(*this == rhs);
}

void Array::reallocate_(unsigned int length) {
    char * temp = new char[length];

    for (int i = 0; i < m_cur_size; i++) {
        temp[i] = m_data[i];
    }

    delete [] m_data;

    m_data = temp;

    m_cur_size = length;
    m_max_size = length;
}