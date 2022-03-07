#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {

	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src ) {

	*this = src;
}

MateriaSource::~MateriaSource() {

	return ;
}

void	MateriaSource::learnMateria( AMateria* m ) {

	this->inv.equip(m);
	return	;
}

AMateria *	MateriaSource::createMateria( std::string const & type ) {

	for (size_t i = 0; i < INVENTORY_SIZE ; i++) {

		AMateria *ptr = this->inv.getMateria(i);

		if (ptr && ptr->getType().compare(type) == 0)
			return ptr->clone();
	}

	return NULL;
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & rhs ) {

	if (this != &rhs)
		this->inv = rhs.inv;
	return *this;
}
