#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal() {

	this->type = "Cat";
	std::cout << this->type << " : Default Cat constructor called" << std::endl;

	return ;
}

Cat::Cat( Cat const & src ) : Animal() {

	*this = src;

	std::cout << this->type << " : Copy Cat constructor called" << std::endl;

	return ;
}

Cat::~Cat() {

	std::cout << this->type << " : Cat destructor called" << std::endl;

	return ;
}

void	Cat::makeSound() const {

	std::cout << this->type << " : \"MEOOOOOOOWW\"" << std::endl;

	return ;
}

Cat &	Cat::operator=( Cat const & rhs ) {

	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}
