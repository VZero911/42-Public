#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal& other);
        Animal &operator=(const Animal& other);
        virtual ~Animal(void);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif