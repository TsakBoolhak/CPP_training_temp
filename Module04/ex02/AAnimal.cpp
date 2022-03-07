#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

AAnimal::AAnimal() : type ( "Some kind of animal" ) {

	std::cout << this->type << " : Default AAnimal constructor called" << std::endl;

	return ;
}

AAnimal::AAnimal( AAnimal const & src ) {

	*this = src;

	std::cout << this->type << " : Copy AAnimal constructor called" << std::endl;

	return ;
}

AAnimal::~AAnimal() {

	std::cout << this->type << " : AAnimal destructor called" << std::endl;

	return ;
}

std::string const & AAnimal::getType() const {

	return type;
}

AAnimal &	AAnimal::operator=( AAnimal const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
