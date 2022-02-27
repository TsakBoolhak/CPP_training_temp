# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

MateriaSource::MateriaSource() {

	return ;
}

MateriaSource(MateriaSource const & src) {

	*this = src;
}

MateriaSource::~MateriaSource() {

	return ;
}

void		learnMateria(AMateria*) {

}

AMateria *	createMateria(std::string const & type) {

}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs) {

}
