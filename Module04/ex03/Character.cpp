#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Inventory.hpp"

Character::Character() : name ( "Def Holt" ) {

	return ;
}

Character::Character( std::string const & name ) : name ( name ) {

	return ;
}

Character::Character( Character const & src ) {

	*this = src;

	return ;
}

Character::~Character() {

	return ;
}

std::string const &	Character::getName() const {

	return this->name;
}

void	Character::equip(AMateria* m) {

	this->inv.equip(m);

	return ;
}

void	Character::unequip(int idx) {

	this->inv.unequip(idx);

	return ;
}

void	Character::use(int idx, ICharacter& target) {

	this->inv.use(idx, target);

	return ;
}

Character &	Character::operator=( Character const & src ) {

	if (this != &src) {

		this->name = src.name;
		this->inv = src.inv;
	}

	return *this;
}
