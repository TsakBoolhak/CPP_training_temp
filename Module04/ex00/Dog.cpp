#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {

	this->type = "Dog";
	std::cout << this->type << " : Default Dog constructor called" << std::endl;

	return ;
}

Dog::Dog( Dog const & src ) : Animal () {

	*this = src;

	std::cout << this->type << " : Copy Dog constructor called" << std::endl;

	return ;
}

Dog::~Dog( void ) {

	std::cout << this->type << " : Dog destructor called" << std::endl;

	return ;
}

void	Dog::makeSound() const {

	std::cout << this->type << " : \"WOOF WOOF!!\"" << std::endl;

	return ;
}

Dog &	Dog::operator=( Dog const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
