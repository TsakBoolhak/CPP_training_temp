#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main()
{
	Brain brain;

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
	
	Cat *cat1 = new Cat();
	Brain	*brainPtr;
	
	brainPtr = cat1->getBrain();
	brainPtr->addIdea("MEOOOW");
	brainPtr->addIdea("I think therefore i am a cat");
	brainPtr->addIdea("PURRRRRR");
	std::cout << "cat1 :" << std::endl;
	brainPtr->printIdeas();
	Cat *cat2 = new Cat(*cat1);
	delete cat1;
	brainPtr = cat2->getBrain();
	std::cout << "cat2 :" << std::endl;
	brainPtr->printIdeas();
	delete cat2;

	Dog *dog1 = new Dog();
	
	brainPtr = dog1->getBrain();
	brainPtr->addIdea("WOOF");
	brainPtr->addIdea("I think therefore i am a dog");
	brainPtr->addIdea("WAF");
	std::cout << "dog1 :" << std::endl;
	brainPtr->printIdeas();
	Dog *dog2 = new Dog(*dog1);
	delete dog1;
	brainPtr = dog2->getBrain();
	std::cout << "dog2 :" << std::endl;
	brainPtr->printIdeas();
	delete dog2;
	
	AAnimal	*animals[10];
	size_t	i = 0;
	while (i < 5) {
		animals[i] = new Dog();
		i++;
	}
	while (i < 10) {
		animals[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < 10) {
		delete animals[i];
		i++;
	}

	/* Uncomment next line to check that AAnimal classe can't be instanciated apart from a classe that inherit it (should not compile)*/
	// AAnimal lol();

	return 0;
}
