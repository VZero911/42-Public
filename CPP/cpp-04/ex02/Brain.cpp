#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructed." << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copied." << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assigned." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
    else
        std::cerr << "Brain::setIdea - Invalid index!" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    std::cerr << "Brain::getIdea - Invalid index!" << std::endl;
    return "";
}
