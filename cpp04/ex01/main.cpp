#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* ii = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << ii->getType() << " " << std::endl;
    // ii->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // const WrongAnimal* x = new WrongCat();
    // std::cout << x->getType() << " " << std::endl;
    // x->makeSound(); 
    // delete meta;
    // std::cout << "------" <<  std::endl;
    // delete j;
    // std::cout << "------" <<  std::endl;
    // delete ii;
    // std::cout << "------" <<  std::endl;
    // delete x;

    // int	n = 10;
	// Animal* animals[n];
	// std::cout << "------create dogs and cats-------" <<  std::endl;
	// for (int i = 0 ; i < n; i++) {
	// 	if (i < (n / 2)) {
	// 		animals[i] = new Dog();
	// 	} else {
	// 		animals[i] = new Cat();
	// 	}
	// }
    // std::cout << "-------Dogs and cats making sound.-------\n" <<  std::endl;
	// for (int i = 0; i < n; i++) {
	// 	std::cout << "Animal type: " << \
	// 		animals[i]->getType() << " " << std::endl;
	// 	animals[i]->makeSound();
	// 	animals[i]->addIdea("idea1");
	// 	animals[i]->addIdea("idea2");
	// 	animals[i]->printOutIdeas();
	// }
    // for (int i = 0; i < n; i++) {
	// 	delete animals[i];
	// }
    std::cout << "~~~~~~Kitty and Cutee's brains~~~~~~\n";
	Cat kitty;
    std::cout << "\n";
	kitty.addIdea("kitty idea 1");
	kitty.addIdea("kitty idea 2");

	Cat cutee(kitty);
	cutee.addIdea("cutee idea 1");
	kitty.printOutIdeas();
    std::cout << "~~~~~~" << std::endl;
	cutee.printOutIdeas();
    
	Cat newCat=cutee;
    std::cout << "~~~~~~" << std::endl;
    newCat.addIdea("new one idea");
    newCat.printOutIdeas();


    return 0;
}