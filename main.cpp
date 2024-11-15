//
// Created by edmond on 10.11.24.
//
#include "linked-list.h"
#include <iostream>

using std::cout, std::endl;

int main(int argc, char* argv[]) {
    linked_list<int> test;
    for(int i = 0; i < 10; ++i) {
        test.push_back(i);
    }
    cout << test << endl;
    return 0;
}