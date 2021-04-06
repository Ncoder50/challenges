#include <iostream>
#include <stdlib.h>

bool isSafeBridge(std::string bridge);

int main() {
    std::cout << std::boolalpha;
    std::cout << "======= Test of bridges =====" << std::endl;
    std::cout << isSafeBridge("####") << std::endl;
    std::cout << isSafeBridge("## ###") << std::endl;
    std::cout << isSafeBridge("#") << std::endl;
    std::cout << "======= Test Done ===========" << std::endl;
    return 0;
}

bool isSafeBridge(std::string bridge) {
    int i;
    for (i = 0; i < bridge.length(); i++) {
        if (bridge.at(i) == ' ')
            return false;
    }
    return true;
}

