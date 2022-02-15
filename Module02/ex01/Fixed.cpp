#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : rawBits ( 0 ) {

	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed( Fixed const &src ) : rawBits ( 0 ) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return ;
}

Fixed::Fixed( const int value ) {

	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value * ( 1 << Fixed::decimalPartSize );

	return ;
}

Fixed::Fixed( const float value ) {

	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf( value * ( 1 << Fixed::decimalPartSize ) );

	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

int	Fixed::getRawBits ( void ) const {

	return this->rawBits;
}

void	Fixed::setRawBits ( int const raw ) {

	this->rawBits = raw;

	return ;
}

int		Fixed::toInt( void ) const {

	return this->rawBits / (1 << this->decimalPartSize);
}

float	Fixed::toFloat( void ) const {

	return (double)(this->rawBits) / (double)(1 << Fixed::decimalPartSize);
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs)
		this->rawBits = rhs.rawBits;

	return *this;
}

std::ostream & operator<<( std::ostream& os, const Fixed& rhs ) {

	os << rhs.toFloat();
	
	return os;
}
