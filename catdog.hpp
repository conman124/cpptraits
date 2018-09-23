#include "cat.hpp"
#include "dog.hpp"

class Catdog : public Cat, public Dog {
    public:
    void speak();
    void meow();
    void bark();
};