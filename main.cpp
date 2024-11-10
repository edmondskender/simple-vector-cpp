//
// Created by edmond on 03.11.24.
//
#include "my_vector.h"
#include <iostream>

using std::cout, std::endl;

int main(int argc, char* argv[]) {
    if(argc != 2) return 0;
    const int n = atoi(argv[1]);
    my_vector primes;
    primes.push_back(2);
    for(int i = 3; i < n; i+=2) {
        bool isPrime = true;
        for(int j = 0; j < primes.size(); ++j) {
            if(i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) primes.push_back(i);
    }
    cout << primes << endl;
    return 0;
}