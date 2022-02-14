#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::Claptrap( void ) : _name ( "Default name" ), _hitPoints ( 10 ), _energyPoints ( 10 ), _attackDamage ( 0 ) {

	std::cout << "Default ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::Claptrap( Claptrap &src ) {

	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::Claptrap( std::string name ) : _name ( name ), _hitPoints ( 10 ), _energyPoints ( 10 ), _attackDamage ( 0 ) {

	std::cout << "String ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::~Claptrap( void ) {

	std::cout << "Claptrap destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack( const std::string& target ) {

	std::cout << this->_name;

	if (this->_hitPoints == 0) {

	std::cout << " is lying on the ground, uncouncious and is unable to attack " << target << "!" << std::endl;
	}

	else if ( this->_energyPoints > 0) {

		this->_energyPoints--;
		std::cout << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	}

	else {

		std::cout << " is too exhausted to attack " << target << " and just mumble under his breath..." << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << this->_name;
	if ( this->_hitPoints == 0 )
		std::cout << " is already lying on the ground uncouncious and can't take any more damage!" << std::endl;
	else if ( amount >= this->_hitPoints) {

		std::cout << " has taken " << this->_hitPoints << " damage and falls uncouncious on the ground as he has 0 hitpoints left!" << std::endl;
		this->hitPoints = 0;
	}
	else {

	this->hitPoints -= amount;
	std::cout << " has taken " << amount << " damage, he now has " << this->hitPoints << " hitpoints left!" << std::endl;
	}

	return;
}

void	Claptrap::beRepaired( unsigned int amount ) {

	std::cout << this->_name;
	if ( this->_hitPoints == 0 ) {

		std::cout << "would have try to repair himself if he wasn't uncouncious!" << std::endl;
	}
	else if (this->_energyPoints == 0) {

		std::cout << "is trying to repair himself but feels too tired to activate this protocol!" << std::endl; 
	}
	else {

		this->_hitPoints = std::numeric_limits<unsigned int>::max - amount < this->_hitPoints ? std::numeric_limits<unsigned int>::max : this->_hitPoints + amount;
		this->_energyPoints--;
		std::cout << "has activated the repair protocol with a voltage of " << amout << "V he now has " << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points left!" << std::endl;
	}
}

Claptrap &	Claptrap::operator=( Claptrap const & rhs ) {

	if (this != rhs) {

		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}
