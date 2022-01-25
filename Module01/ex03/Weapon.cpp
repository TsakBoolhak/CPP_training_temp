#include <string>
#include "Weapon.hpp"

Weapon::Weapon( std::string initType ) : type (initType), typeRef (type) {

	return ;
}

Weapon::~Weapon( void ) {

	return ;
}



void				Weapon::setType( std::string newType ) {
	
	this->type = newType;
	this->typeRef = this->type;
}

const std::string& Weapon::getType( void ) const {

	return (this->typeRef);
}
