#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}
