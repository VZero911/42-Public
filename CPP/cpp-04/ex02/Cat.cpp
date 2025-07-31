#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}
