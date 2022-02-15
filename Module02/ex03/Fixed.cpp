#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : rawBits ( 0 ) {

//	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &src ) {

//	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return ;
}

Fixed::Fixed( const float value ) {

//	std::cout << "Float constructor called" << std::endl;

	this->rawBits = ( roundf( value * ( 1 << this->decimalPartSize ) ) );

	return ;
}

Fixed::Fixed( const int value ) {

//	std::cout << "Int constructor called" << std::endl;

	this->rawBits = ( value * ( 1 << this->decimalPartSize ) );

	return ;
}

Fixed::~Fixed( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}

int	Fixed::getRawBits ( void ) const {

//	std::cout << "getRawBits member function called" << std::endl;

	return this->rawBits;
}

void	Fixed::setRawBits ( int const raw) {

//	std::cout << "setRawBits member function called" << std::endl;

	this->rawBits = raw;

	return ;
}

int		Fixed::toInt( void ) const {

//	std::cout << "toInt member function called" << std::endl;

	return this->rawBits / (1 << this->decimalPartSize);
}

float	Fixed::toFloat( void ) const {

//	std::cout << "toFloat member function called" << std::endl;

	return (double)(this->rawBits) / (double)(1 << this->decimalPartSize);
}

Fixed &	Fixed::min( Fixed & a, Fixed & b ) {

	return a < b ? a : b;
}

Fixed &	Fixed::max( Fixed & a, Fixed & b ) {

	return a > b ? a : b;
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b ) {

	return a < b ? a : b;
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b ) {

	return a > b ? a : b;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

//	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs)
		this->rawBits = rhs.getRawBits();

	return *this;
}

bool	Fixed::operator>( Fixed const & rhs ) const {

	return this->rawBits > rhs.getRawBits();
}

bool	Fixed::operator<( Fixed const & rhs ) const {

	return this->rawBits < rhs.getRawBits();
}

bool	Fixed::operator>=( Fixed const & rhs ) const {

	return this->rawBits >= rhs.getRawBits();
}

bool	Fixed::operator<=( Fixed const & rhs ) const {

	return this->rawBits <= rhs.getRawBits();
}

bool	Fixed::operator==( Fixed const & rhs ) const {

	return this->rawBits == rhs.getRawBits();
}

bool	Fixed::operator!=( Fixed const & rhs ) const {

	return this->rawBits != rhs.getRawBits();
}

Fixed	Fixed::operator+( const Fixed & rhs ) {

	Fixed ret ( *this );

	ret.rawBits += rhs.getRawBits();
	return ret;
}

Fixed	Fixed::operator-( const Fixed & rhs ) {

	Fixed ret ( *this );

	ret.rawBits -= rhs.getRawBits();
	return ret;
}

Fixed	Fixed::operator*( const Fixed & rhs ) {

	Fixed ret;

	ret.rawBits = ((int64_t)(this->rawBits) * (int64_t)(rhs.rawBits)) / (1 << Fixed::decimalPartSize);
	return ret;
}

Fixed	Fixed::operator/( const Fixed & rhs ) {

	Fixed ret;

	ret.rawBits = (int64_t)(this->rawBits) * (1 << Fixed::decimalPartSize) / (int64_t)(rhs.rawBits);
	return ret;
}

Fixed &	Fixed::operator++( void ) {

	this->rawBits += 1;
	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed	ret = *this;

	operator++();
	return	ret;
}

Fixed &	Fixed::operator--( void ) {

	this->rawBits -= 1;
	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed	ret = *this;

	operator--();
	return	ret;
}

std::ostream & operator<<( std::ostream& os, const Fixed& rhs ) {

	os << rhs.toFloat();
	
	return os;
}
