#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& other);

        void makeSound() const;
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif