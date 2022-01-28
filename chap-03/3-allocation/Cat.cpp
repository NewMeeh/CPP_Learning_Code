#include "Cat.h"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("Felix");
    std::unique_ptr<Cat> cat2;
    cat2 = std::make_unique<Cat>("Felix");

    if (cat2 == nullptr)
    { std::cout << "est bien nullptr" << std::endl; }

    if (cat == cat2)
    { std::cout << "meme pointeurs" << std::endl; }
    if (*cat == *cat2)
    { std::cout << "meme objets" << std::endl; }

    std::cout << *cat << std::endl;
    return 0;
}