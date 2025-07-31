#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);

        void makeSound() const;
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif