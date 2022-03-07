#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Animal::Animal() : type ( "Some kind of animal" ) {

	std::cout << this->type << " : Default Animal constructor called" << std::endl;

	return ;
}

Animal::Animal( Animal const & src ) {

	*this = src;

	std::cout << this->type << " : Copy Animal constructor called" << std::endl;

	return ;
}

Animal::~Animal() {

	std::cout << this->type << " : Animal destructor called" << std::endl;

	return ;
}

void	Animal::makeSound() const {

	std::cout << this->type << " : \"mlhdglouqods\" (some undefined animal noise)" << std::endl;

	return ;
}

std::string const & Animal::getType() const {

	return this->type;
}

Brain	*Animal::getBrain() const {

	return NULL;
}

Animal &	Animal::operator=( Animal const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
