#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria( void ) {

	return ;
}

AMateria::AMateria( std::string const & type ) {

	this->type = type;
	return ;
}

AMateria::AMateria( AMateria const & src ) {

	*this = src;
	return ;
}

AMateria::~AMateria( void ) {

	return ;
}

AMateria &	AMateria::operator=( AMateria const & rhs ) {

	(void)rhs;

	return *this;
}

std::string const & AMateria::getType() const {

	return this->type;
}

void	AMateria::use(ICharacter& target) {

	std::cout << "* Looking intensively at " << target.getName() << " *" << std::endl;
	return ;
}
