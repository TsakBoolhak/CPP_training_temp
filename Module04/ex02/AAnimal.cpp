#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal( void ) : type ( "Some kind of animal" ) {

	std::cout << this->type << " : Default AAnimal constructor called" << std::endl;

	return ;
}

AAnimal::AAnimal( AAnimal const & src ) {

	*this = src;

	std::cout << this->type << " : Copy AAnimal constructor called" << std::endl;

	return ;
}

AAnimal::~AAnimal( void ) {

	std::cout << this->type << " : AAnimal destructor called" << std::endl;

	return ;
}

std::string const & AAnimal::getType() const {

	return type;
}

/*Brain	*AAnimal::getBrain() const {

	return NULL;
}*/

AAnimal &	AAnimal::operator=( AAnimal const & rhs ) {

	std::cout << "LOL" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
