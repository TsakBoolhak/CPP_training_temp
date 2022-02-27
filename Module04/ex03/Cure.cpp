#include <string>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("ice") {

	return ;
}

Cure::Cure( Cure const & src ) AMateria("ice"); {

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

void	use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

	return ;
}
