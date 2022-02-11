#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : rawBits ( 0 ) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed &src ) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return ;
}

Fixed::Fixed( const int value ) {

	std::cout << "Int constructor called" << std::endl;
	this->rawBits = (int)( roundf( value * ( 1 << this->decimalPartSize ) ) );
}

Fixed::Fixed( const float value ) {

	std::cout << "Float constructor called" << std::endl;
	this->rawBits = (int)( value * ( 1 << this->decimalPartSize ) );
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

int		Fixed::toInt( void ) const {

	return this->rawBits / (1 << this->decimalPartSize);
}

float	Fixed::toFloat( void ) const {

	return double(this->rawBits) / double(1 << this->decimalPartSize);
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs)
		this->rawBits = rhs.getRawBits();

	return *this;
}

std::ostream & operator<<( std::ostream& os, const Fixed& rhs ) {

	std::cout << rhs.toFloat();
	
	return os;
}
