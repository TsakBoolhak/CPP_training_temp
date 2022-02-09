#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : rawBits ( 0 ) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed &src ) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

int	Fixed::getRawBits ( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return this->rawBits;
}

void	Fixed::setRawBits ( int const raw) {

	std::cout << "setRawBits member function called" << std::endl;

	this->rawBits = raw;

	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	this->rawBits = rhs.getRawBits();

	return *this;
}

