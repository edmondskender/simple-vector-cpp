#pragma once

#include <iostream>

class my_vector {
    int* data;
    int _size;
    int _capacity;
    void resize(int new_capacity);

public:
    my_vector();
    explicit my_vector(int len, int val=0);
    ~my_vector();
    my_vector(const my_vector& other);
    my_vector& operator=(const my_vector& other);
    my_vector(my_vector&& other) noexcept;
    my_vector& operator=(my_vector&& other) noexcept;
    void push_back(int x);
    const int& operator[](int idx) const;
    int& operator[](int idx);
    int size() const;
    int capacity() const;
    bool empty() const;
    friend std::ostream& operator<<(std::ostream& os, const my_vector& obj);
};