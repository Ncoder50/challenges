#include <iostream>
#include "bigInt.hpp"

bigInt::bigInt() {
    values = (int*)calloc(100000, sizeof *values);
    if (values == nullptr)
        std::cout << "Allocation for value vector failed!" 
            << std::endl;
    len = 0;
    zeros = 0;
}

void bigInt::set_value(int x) {
    start_value = x;
    for (int i = 0; x > 0; x /= 10, i++) {
        values[i] = x % 10;
        len++;
    }
}

void bigInt::factorial() {
    for (int i = start_value - 1; i > 1; i--)
        multiply(i);
    trail();
}

void bigInt::print() {
    std::cout << "Prints factorial: ";
    for (int i = len - 1; i >= 0; i--)
        std::cout << values[i];
    std::cout << std::endl;
    std::cout << "Number of zeros in trail: " 
            << zeros << std::endl << "\n\n";
}

void bigInt::free_class() {
    free(values);
}

void bigInt::clean() {
    len = 0;
    zeros = 0;
}


void bigInt::multiply(int other) {
    int i, rest;
    rest = 0;
    for (i = 0; i < len; i++) {
        values[i] *= other;
        values[i] += rest;
        if (values[i] > 9) {
            rest = values[i] / 10;
            values[i] %= 10;
            if (i + 1 == len) {
                while (rest > 0) {
                    values[len] = rest % 10;
                    len++;
                    rest /= 10;
                }
                return;
            }
        }
        else {
            rest = 0;
        }
    }
}

void bigInt::trail() {
    int i = 0;
    while (!values[i]) {
        zeros++;
        i++;
    }
}

