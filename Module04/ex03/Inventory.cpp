#include <iostream>
#include "Inventory.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Inventory::Inventory() {

	for ( size_t i = 0 ; i < INVENTORY_SIZE ; i++ )
		this->materias[i] = NULL;

	return;
}

Inventory::Inventory( Inventory const & src ) {

	for ( size_t i = 0 ; i < INVENTORY_SIZE ; i++ )
		this->materias[i] = NULL;
	*this = src;

	return ;
}
Inventory::~Inventory() {

	for ( size_t i = 0 ; i < INVENTORY_SIZE ; i++ )
	{
		if ( this->materias[i] )
			delete this->materias[i];
	}

	return ;
}

AMateria	*Inventory::getMateria( int idx ) const {

	if ( idx >= 0 && idx < INVENTORY_SIZE )
		return this->materias[idx];
	else
		return NULL;
}

void	Inventory::equip( AMateria* m ) {

	size_t i = 0;

	for ( ; i < INVENTORY_SIZE && this->materias[i] != NULL ; i++ )
		;
	if ( i < INVENTORY_SIZE )
		this->materias[i] = m;
	else
		std::cout << "Inventory is full" << std::endl;

	return ;
}

void	Inventory::unequip( int idx ) {

	if ( idx >= 0 && idx < INVENTORY_SIZE && this->materias[idx] != NULL )
		this->materias[idx] = NULL;
	else if ( idx >= 0 && idx < INVENTORY_SIZE )
		std::cout << "This inventory slot is alrdy empty" << std::endl;
	else
		std::cout << "You tried to unequip a wrong index of inventory" << std::endl;

	return ;
}

void	Inventory::use( int idx, ICharacter& target ) const {

	if ( idx >= 0 && idx < INVENTORY_SIZE && this->materias[idx] != NULL )
		this->materias[idx]->use(target);

	return ;
}

Inventory &	Inventory::operator=( Inventory const & rhs ) {

	if ( this != &rhs ) {

		for ( size_t i = 0 ; i < INVENTORY_SIZE ; i++ ) {
			
			if ( this->materias[i] )
				delete this->materias[i];
			this->materias[i] = rhs.materias[i]->clone();
		}
	}

	return *this;
}
