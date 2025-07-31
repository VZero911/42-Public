#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Uncommenting the following line should cause a compile error,
    // because AAnimal is abstract (cannot instantiate):
    // AAnimal a;

    // Polymorphic usage through Animal pointers:
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    std::cout << "Dog says: ";
    dog->makeSound();

    std::cout << "Cat says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}
