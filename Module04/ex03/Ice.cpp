# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

Ice::Ice( void ) : AMateria("ice") {

	return ;
}

Ice::Ice( Ice const & src ) AMateria("ice"); {

	return ;
}

Ice::~Ice( void ) {

	return ;
}

Ice &	Ice::operator=( Ice const & rhs ) {

	(void)rhs;

	return *this;
}

Ice*	Ice::clone() const {

	return new Ice();
}

void	use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

	return ;
}
