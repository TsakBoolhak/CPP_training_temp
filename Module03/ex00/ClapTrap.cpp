#include <iostream>
#include <limits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name ( "Default name" ), _hitPoints ( 10 ), _energyPoints ( 10 ), _attackDamage ( 0 ) {

	std::cout << this->_name << " : Default ClapTrap constructor called" << std::endl;

	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	*this = src;

	std::cout << this->_name << " : Copy ClapTrap constructor called" << std::endl;

	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name ( name ), _hitPoints ( 10 ), _energyPoints ( 10 ), _attackDamage ( 0 ) {

	std::cout << this->_name << " : String ClapTrap constructor called" << std::endl;

	return ;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << this->_name << " : Claptrap destructor called" << std::endl;

	return ;
}

void	ClapTrap::attack( const std::string& target ) {

	std::cout << this->_name;

	if (this->_hitPoints == 0)
	std::cout << " is lying on the ground, uncouncious and is unable to attack " << target << "!" << std::endl;

	else if ( this->_energyPoints > 0) {

		this->_energyPoints--;
		std::cout << " attacks " << target << ", causing " << this->_attackDamage << " points of damage ! He now has " << this->_energyPoints << " energy points left!"<< std::endl;
	}

	else
		std::cout << " is too exhausted to attack " << target << " and just mumble under his breath..." << std::endl;

	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << this->_name;

	if ( this->_hitPoints == 0 )
		std::cout << " is already lying on the ground uncouncious and can't take any more damage!" << std::endl;

	else if ( amount >= this->_hitPoints) {

		std::cout << " has taken " << this->_hitPoints << " damage";
		if( amount > this->_hitPoints )
			std::cout << " out of the " << amount << " potential damage of the attack";
		std::cout << " and falls uncouncious on the ground as he has 0 hitpoints left!" << std::endl;
		this->_hitPoints = 0;
	}

	else {

		this->_hitPoints -= amount;
		std::cout << " has taken " << amount << " damage, he now has " << this->_hitPoints << " hitpoints left!" << std::endl;
	}

	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	std::cout << this->_name;

	if ( this->_hitPoints == 0 )
		std::cout << " would have try to repair himself if he wasn't uncouncious!" << std::endl;

	else if (this->_energyPoints == 0)
		std::cout << " is trying to repair himself but feels too tired to activate this protocol!" << std::endl; 

	else {

		this->_hitPoints = std::numeric_limits<unsigned int>::max() - amount < this->_hitPoints ? std::numeric_limits<unsigned int>::max() : this->_hitPoints + amount;
		this->_energyPoints--;

		std::cout << " has activated the repair protocol with a voltage of " << amount << "V he now has " << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points left!" << std::endl;
	}

	return ;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {

	if (this != &rhs) {

		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return *this;
}
