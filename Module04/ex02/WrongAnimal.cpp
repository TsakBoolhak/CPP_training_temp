#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal( void ) : type ( "Some kind of wrong animal" ) {

	std::cout << this->type << " : Default WrongAnimal constructor called" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {

	*this = src;

	std::cout << this->type << " : Copy WrongAnimal constructor called" << std::endl;

	return ;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << this->type << " : WrongAnimal destructor called" << std::endl;

	return ;
}

void	WrongAnimal::makeSound() const {

	std::cout << this->type << " : \"glarglourg\" (some undefined wrong animal noise)" << std::endl;

	return ;
}

std::string const & WrongAnimal::getType() const {

	return this->type;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
