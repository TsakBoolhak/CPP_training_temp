#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {

	this->type = "Dog";
	this->brain = new Brain();
	std::cout << this->type << " : Default Dog constructor called" << std::endl;

	return ;
}

Dog::Dog( Dog const & src ) : Animal () {

	this->brain = new Brain();
	*this = src;

	std::cout << this->type << " : Copy Dog constructor called" << std::endl;

	return ;
}

Dog::~Dog( void ) {

	delete this->brain;
	std::cout << this->type << " : Dog destructor called" << std::endl;

	return ;
}

Brain	*Dog::getBrain() const {

	return this->brain;
}

void	Dog::makeSound() const {

	std::cout << this->type << " : \"WOOF WOOF!!\"" << std::endl;

	return ;
}

Dog &	Dog::operator=( Dog const & rhs ) {

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
