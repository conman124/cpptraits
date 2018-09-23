#pragma once

#include "cat.hpp"
#include "dog.hpp"
#include "traits.hpp"

class Catdog : public Traits<Cat, Dog> {
    public:
    void speak();
    void meow();
    void bark();
};