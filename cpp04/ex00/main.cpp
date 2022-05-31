#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    

    const WrongAnimal* x = new WrongCat();
    std::cout << x->getType() << " " << std::endl;
    x->makeSound(); 
    delete meta;
    delete j;
    delete i;
    delete x;
    return 0;
}