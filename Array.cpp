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

unsigned int Array::get_size() {
    return m_cur_size;
}

unsigned int Array::get_max_size() {
    return m_max_size;
}

void Array::set_element(unsigned int index, char el) {
    m_data[index] = el;
}

char Array::get_element(unsigned int index) {
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

int Array::find(char target) {
    for (int i = 0; i < m_cur_size; i++) {
        if (m_data[i] == target) {
            return i;
        }
    }
    return -1;
}

char & Array::operator [] (unsigned int index) {
    return m_data[index];
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