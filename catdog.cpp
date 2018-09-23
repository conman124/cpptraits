#include <iostream>

#include "catdog.hpp"

void Catdog::speak() {
    meow();
    bark();
}

void Catdog::bark() {
    std::cout << "bark" << std::endl;
}

void Catdog::meow() {
    std::cout << "meow" << std::endl;
}