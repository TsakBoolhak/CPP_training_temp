#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	std::cout << "------------CONSTRUCTORS' MESSAGES------------" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongI = new WrongCat();

	std::cout << std::endl << "--------END OF CONSTRUCTORS' MESSAGES---------" << std::endl;

	std::cout << std::endl << "---------------ANIMALS' MESSAGES--------------" << std::endl << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "----------END OF ANIMALS' MESSAGES------------" << std::endl << std::endl;

	std::cout << std::endl << "------------WRONG ANIMALS' MESSAGES-----------" << std::endl << std::endl;

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;
	wrongMeta->makeSound();
	wrongI->makeSound();

	std::cout << std::endl << "--------END OF WRONG ANIMALS' MESSAGES--------" << std::endl << std::endl;

	std::cout << std::endl << "------------DESTRUCTORS' MESSAGES-------------" << std::endl << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongI;

	std::cout << std::endl << "---------END OF DESTRUCTORS' MESSAGES---------" << std::endl;

	return 0;
}
