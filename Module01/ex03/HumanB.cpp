#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string assignName ) : name ( assignName ) {
	
	weapon = NULL;
	return ;
};

HumanB::~HumanB( void ) {
	
	return ;
}

void	HumanB::attack (void ) {

	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;

	else
		std::cout << this->name << " try to grab their weapon but remember he doesnt have any..." << std::endl;

	return ;
}

void	HumanB::setWeapon (Weapon newWeapon) {

	//std::string newType = newWeapon.getType();
	this->weapon = &newWeapon;
//	this->weapon = this->weaponRef;

	return ;
}
