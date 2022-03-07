#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{

	std::cout << "----------------SUBJECT'S MAIN----------------" << std::endl << std::endl;
	{
		std::cout << "------------CONSTRUCTORS' MESSAGES------------" << std::endl;

		const Animal* meta = new Animal();

		std::cout << std::endl;

		const Animal* j = new Dog();

		std::cout << std::endl;

		const Animal* i = new Cat();

		std::cout << "----------------------------------------------" << std::endl;

		std::cout << std::endl << "---------------ANIMALS' MESSAGES--------------" << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << "----------------------------------------------" << std::endl;

		std::cout << std::endl << "------------DESTRUCTORS' MESSAGES-------------" << std::endl;

		delete meta;

		std::cout << std::endl;

		delete j;

		std::cout << std::endl;

		delete i;

		std::cout << "----------------------------------------------" << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << "-----------------OTHER TESTS------------------" << std::endl << std::endl;
	{
		std::cout << "------------CONSTRUCTORS' MESSAGES------------" << std::endl;

		const WrongAnimal *wrongMeta = new WrongAnimal();

		std::cout << std::endl;

		const WrongAnimal *wrongI = new WrongCat();

		std::cout << "----------------------------------------------" << std::endl;

		std::cout << std::endl << "------------WRONG ANIMALS' MESSAGES-----------" << std::endl;

		std::cout << wrongMeta->getType() << " " << std::endl;
		std::cout << wrongI->getType() << " " << std::endl << std::endl;
		wrongMeta->makeSound();
		wrongI->makeSound();

		std::cout << "----------------------------------------------" << std::endl;

		std::cout << std::endl << "------------DESTRUCTORS' MESSAGES-------------" << std::endl;

		delete wrongMeta;

		std::cout << std::endl;

		delete wrongI;

		std::cout << "----------------------------------------------" << std::endl;
	}

	return 0;
}
