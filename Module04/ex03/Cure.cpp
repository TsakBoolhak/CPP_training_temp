#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure") {

	return ;
}

Cure::Cure( Cure const & src ) : AMateria("cure") {

	*this = src;
	return ;
}

Cure::~Cure( void ) {

	return ;
}

Cure &	Cure::operator=( Cure const & rhs ) {

	(void)rhs;

	return *this;
}

Cure*	Cure::clone() const {

	return new Cure();
}

void	Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

	return ;
}
