#include "Data.hpp"
#include <string>
#include <iostream>

Data::Data() : _someInt ( 42 ), _someFloat ( 4.2f ), _someString ( " 21 * 2 " ) {

	return ;
}

Data::Data( int const i, float const f, std::string const & str ) : _someInt ( i), _someFloat ( f ), _someString ( str ) {

	return ;
}

Data::Data( Data const & src ) {

	*this = src;

	return ;
}

Data::~Data() {

	return ;
}

int	Data::getInt() const {

	return this->_someInt;
}
float	Data::getFloat() const {

	return this->_someFloat;
}

std::string	Data::getString() const {

	return this->_someString;
}

void	Data::setInt( int const i ) {

	this->_someInt = i;
}

void	Data::setFloat( float const f ) {

	this->_someFloat = f;
}

void	Data::setString( std::string const & str ) {

	this->_someString = str;
}

Data &	Data::operator=( Data const & rhs ) {

	if ( this != &rhs ) {

		this->_someInt = rhs._someInt;
		this->_someFloat = rhs._someFloat;
		this->_someString = rhs._someString;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, Data const & rhs) {

	os << "Datas : _someInt = " << rhs.getInt() << ", _someFloat = " << rhs.getFloat() << ", _someString = " << rhs.getString();

	return os;
}
