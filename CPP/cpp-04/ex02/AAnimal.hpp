#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal& other);
        AAnimal &operator=(const AAnimal& other);
        virtual ~AAnimal(void);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif