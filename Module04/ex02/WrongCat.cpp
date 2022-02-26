#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal() {

	this->type = "WrongCat";
	std::cout << this->type << " : Default WrongCat constructor called" << std::endl;

	return ;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal() {

	*this = src;

	std::cout << this->type << " : Copy WrongCat constructor called" << std::endl;

	return ;
}

WrongCat::~WrongCat( void ) {

	std::cout << this->type << " : WrongCat destructor called" << std::endl;

	return ;
}

void	WrongCat::makeSound() const {

	std::cout << this->type << " : \"MEOOOOOOOWW\"" << std::endl;

	return ;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
