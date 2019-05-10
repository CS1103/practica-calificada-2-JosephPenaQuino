#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#endif