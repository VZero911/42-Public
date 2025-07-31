#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int ARRAY_SIZE = 4;
    Animal* animals[ARRAY_SIZE];

    std::cout << "\n--- Creating Animals (2 Dogs, 2 Cats) ---\n" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if (i < ARRAY_SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing makeSound() for all Animals ---\n" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Testing Deep Copy of Dog ---\n" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Chase the mailman");
    Dog copiedDog = originalDog;

    std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copiedDog.getIdea(0) << std::endl;

    copiedDog.setIdea(0, "Eat the bone");
    std::cout << "\nAfter modifying copied dog idea[0]:" << std::endl;
    std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n--- Deleting all Animals ---\n" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i)
        delete animals[i];

    return 0;
}
