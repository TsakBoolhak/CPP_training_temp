#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main()
{

	std::cout << "---------------TESTING BRAIN CLASS---------------" << std::endl << std::endl;
	{
		
		std::cout << "-BRAIN CONSTRUCTOR-" << std::endl;
		Brain brain;
		std::cout << std::endl;

		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;
	
		brain.addIdea("I think therefore i am");
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.addIdea("But am i thinking?");
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.deleteIdea(0);
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.addIdea("I think that i am thinking");
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.deleteIdea(0);
		brain.deleteIdea(0);
		brain.deleteIdea(0);
		brain.deleteIdea(0);
		brain.deleteIdea(0);
		brain.deleteIdea(0);
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.addIdea("I think therefore i am");
		brain.addIdea("But am i thinking?");
		brain.addIdea("I think that i am thinking");
		brain.addIdea("But do you think i am thinking?");
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.deleteIdea(brain.getIdeasCount());
		brain.deleteIdea(2);
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.printIdea(10);
		brain.printIdea(4);
		brain.printIdea(1);
		std::cout << std::endl;

		for (size_t i = 0; i < 500; i++)
			brain.addIdea("I'm thinking a lot but it leads to nothing");
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		brain.clearIdeas();
		brain.printIdeas();
		std::cout << "brain's ideas count : " << brain.getIdeasCount() << std::endl << std::endl;

		std::cout << "-BRAIN DESTRUCTOR-" << std::endl;
	}
	
	std::cout << std::endl << "----------TESTING CAT CLASS DEEP COPY----------" << std::endl << std::endl;
	{
		std::cout << "-CAT1 CONSTRUCTOR-" << std::endl;
		Cat *cat1 = new Cat();
		std::cout << std::endl;

		Brain	*brainPtr;

		brainPtr = cat1->getBrain();
		brainPtr->addIdea("MEOOOW");
		brainPtr->addIdea("I think therefore i am a cat");
		brainPtr->addIdea("PURRRRRR");

		std::cout << "cat1 ideas :" << std::endl;
		brainPtr->printIdeas();
		std::cout << std::endl;

		std::cout << "-CAT2 CONSTRUCTOR-" << std::endl;
		Cat *cat2 = new Cat(*cat1);
		std::cout << std::endl;

		std::cout << "-CAT1 DESTRUCTOR-" << std::endl;
		delete cat1;
		std::cout << std::endl;

		brainPtr = cat2->getBrain();
		std::cout << "cat2 ideas:" << std::endl;
		brainPtr->printIdeas();
		std::cout << std::endl;

		std::cout << "-CAT2 DESTRUCTOR-" << std::endl;
		delete cat2;
		std::cout << std::endl;
	}

	std::cout << std::endl << "----------TESTING DOG CLASS DEEP COPY----------" << std::endl << std::endl;
	{
		std::cout << "-DOG1 CONSTRUCTOR-" << std::endl;
		Dog *dog1 = new Dog();
		std::cout << std::endl;
	
		Brain	*brainPtr;

		brainPtr = dog1->getBrain();
		brainPtr->addIdea("WOOF");
		brainPtr->addIdea("I think therefore i am a dog");
		brainPtr->addIdea("WAF");

		std::cout << "dog1 ideas :" << std::endl;
		brainPtr->printIdeas();
		std::cout << std::endl;

		std::cout << "-DOG2 CONSTRUCTOR-" << std::endl;
		Dog *dog2 = new Dog(*dog1);
		std::cout << std::endl;

		std::cout << "-DOG1 DESTRUCTOR-" << std::endl;
		delete dog1;
		std::cout << std::endl;

		brainPtr = dog2->getBrain();
		std::cout << "dog2 ideas :" << std::endl;
		brainPtr->printIdeas();
		std::cout << std::endl;

		std::cout << "-DOG2 DESTRUCTOR-" << std::endl;
		delete dog2;
		std::cout << std::endl;
	}

	std::cout << std::endl << "------TESTING DEL DOG AND CAT AS ANIMALS-------" << std::endl << std::endl;
	{
		AAnimal	*animals[10];
		size_t	i = 0;

		std::cout << "-CREATING 5 DOGS-" << std::endl << std::endl;
		while (i < 5) {
			animals[i] = new Dog();
			i++;
			std::cout << std::endl;
		}
		std::cout << "-CREATING 5 CATS-" << std::endl << std::endl;
		while (i < 10) {
			animals[i] = new Cat();
			i++;
			std::cout << std::endl;
		}
		i = 0;
		std::cout << "-DELETING 10 ANIMALS-" << std::endl << std::endl;
		while (i < 10) {
			delete animals[i];
			i++;
			std::cout << std::endl;
		}
		return 0;
	}

	/* Uncomment next line to check that AAnimal classe can't be instanciated apart from a classe that inherit it (should not compile)*/
	// AAnimal lol();
}
