#include "my_vector.h"
#include <iostream>

my_vector::my_vector() : data(nullptr), _size(0), _capacity(0) {};

my_vector::my_vector(const int len, const int val) : _size(len), _capacity(len) {
    data = new int[_capacity];
    for(int i = 0; i < _capacity; ++i)
        data[i] = val;
}

my_vector::~my_vector() {
    delete[] data;
}

my_vector::my_vector(const my_vector& other) : _size(other._size), _capacity(other._capacity) {
    data = new int[_capacity];
    for(int i = 0; i < _size; ++i)
        data[i] = other.data[i];
}

my_vector& my_vector::operator=(const my_vector &other) {
    if(this != &other) {
        delete[] data;
        _size = other._size;
        _capacity = other._capacity;
        data = new int[_capacity];
        for(int i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

my_vector::my_vector(my_vector&& other) noexcept {
    _capacity = other._capacity;
    _size = other._size;
    data = other.data;
    other.data = nullptr;
    other._capacity = other._size = 0;
}

my_vector& my_vector::operator=(my_vector&& other) noexcept {
    if(this != &other) {
        delete[] data;
        _capacity = other._capacity;
        _size = other._size;
        data = other.data;
        other.data = nullptr;
        other._capacity = other._size = 0;
    }
    return *this;
}

const int& my_vector::operator[](const int idx) const {
    return data[idx];
}

int& my_vector::operator[](const int idx) {
    return data[idx];
}

std::ostream& operator<<(std::ostream& os, const my_vector& obj) {
    os << "[ ";
    for(int i = 0; i < obj._size; ++i) {
        os << obj[i];
        if(i == obj._size - 1) {
            os << " ";
        } else {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int my_vector::capacity() const {
    return _capacity;
}

int my_vector::size() const {
    return _size;
}

bool my_vector::empty() const {
    return _size == 0;
}

void my_vector::push_back(int x) {
    if(_size == _capacity) resize(_capacity == 0 ? 1 : _capacity * 2);
    data[_size] = x;
    ++_size;
}


void my_vector::resize(int new_capacity) {
    int* new_data = new int[new_capacity];
    for(int i = 0; i < _size; ++i)
        new_data[i] = std::move(data[i]);
    delete[] data;
    data = new_data;
    _capacity = new_capacity;
}










