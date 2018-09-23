#include <iostream>

#include "catdog.hpp"
#include "cat.hpp"
#include "dog.hpp"

int main(int argc, char** argv) {
    Catdog catdog;
    catdog.speak();

    std::cout << "With traits:" << std::endl;
    catdog.as<Dog>()->bark();
    catdog.as<Cat>()->meow();
}