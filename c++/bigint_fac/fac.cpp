#include <iostream>
#include "bigInt.hpp"

int main() {
    int val;
    bigInt x;
    while (true) {
        std::cout << "Calculate trail of zeros of number: ";
        std::cin >> val;
        x.set_value(val);
        x.factorial();
        x.print();
        x.clean();
    }
    x.free_class();
    return 0;
}