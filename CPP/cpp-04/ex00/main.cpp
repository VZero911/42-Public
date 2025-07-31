#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Correct Animal Tests =====" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n===== Wrong Animal Tests =====" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n===== Additional Tests =====" << std::endl;
    
    std::cout << "\n-- Testing copy constructor --" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    
    Cat cat1;
    Cat cat2(cat1);
    
    std::cout << "\n-- Testing assignment operator --" << std::endl;
    Dog dog3;
    dog3 = dog1;
    
    Cat cat3;
    cat3 = cat1;
    
    return 0;
}