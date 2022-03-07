#include "Cat.hpp"
#include "AAnimal.hpp"
#include <iostream>

Cat::Cat() : AAnimal() {

	this->type = "Cat";

	this->brain = new Brain();

	std::cout << this->type << " : Default Cat constructor called" << std::endl;

	return ;
}

Cat::Cat( Cat const & src ) : AAnimal() {

	this->brain = new Brain();

	*this = src;

	std::cout << this->type << " : Copy Cat constructor called" << std::endl;

	return ;
}

Cat::~Cat() {

	std::cout << this->type << " : Cat destructor called" << std::endl;

	delete this->brain;

	return ;
}

void	Cat::makeSound() const {

	std::cout << this->type << " : \"MEOOOOOOOWW\"" << std::endl;

	return ;
}

Brain	*Cat::getBrain() const {

	return this->brain;
}

Cat &	Cat::operator=( Cat const & rhs ) {

	if (this != &rhs) {

		this->type = rhs.type;
		Brain	*rhsBrain = rhs.getBrain();
		
		if ( rhsBrain && this->brain ) {

			this->brain->clearIdeas();

			for (size_t i = 0 ; i < rhsBrain->getIdeasCount() ; i++)
				this->brain->addIdea(rhsBrain->getIdea(i));
		}
	}

	return *this;
}
