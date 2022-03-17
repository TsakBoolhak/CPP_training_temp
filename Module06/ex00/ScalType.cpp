#include "ScalType.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <limits>
#include <cmath>

ScalType::ScalType( char const * str ) : _toConv ( str ), _type (ScalType::ISIMPOSSIBLE), _c (0), _i (0), _f (0.f), _d (0.) {

 	_outOfRange[ScalType::ISCHAR] = false;
	_outOfRange[ScalType::ISINT] = false;
	_outOfRange[ScalType::ISFLOAT] = false;
 	_outOfRange[ScalType::ISDOUBLE] = false;
	_nonDisplayableChar = false;
	_specialFloatValues = false;

	this->setType();
	switch (this->_type) {

		case ScalType::ISCHAR :
			std::cout << "Converting from char :" << std::endl;
			break;
		case ScalType::ISINT :
			std::cout << "Converting from int :" << std::endl;
			break;
		case ScalType::ISFLOAT :
			std::cout << "Converting from float :" << std::endl;
			break;
		case ScalType::ISDOUBLE :
			std::cout << "Converting from double :" << std::endl;
			break;
		case ScalType::ISIMPOSSIBLE :
			std::cout << "Convertion unknown :" << std::endl;
			break;
	}

	this->convToInt();
	this->convToFloat();
	this->convToDouble();
	this->convToChar();

	return;
}

ScalType::~ScalType() {

	return ;
}

void	ScalType::displayConversions() const {

	std::cout << "char: ";
	if ( this->_type == ScalType::ISIMPOSSIBLE || this->_specialFloatValues == true )
		std::cout << "impossible";
	else if ( this->_outOfRange[ScalType::ISCHAR] == true )
		std::cout << "Out of char's range";
	else if ( this->_nonDisplayableChar == true )
		std::cout << "Non displayable";
	else
		std::cout << "'" << this->_c << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if ( this->_type == ScalType::ISIMPOSSIBLE || this->_specialFloatValues == true )
		std::cout << "impossible";
	else if ( this->_outOfRange[ScalType::ISINT] == true )
		std::cout << "Out of int's range";
	else
		std::cout << this->_i;
	std::cout << std::endl;

	std::cout << "float: ";
	if ( this->_type == ScalType::ISIMPOSSIBLE )
		std::cout << "impossible";
	else if (this->_type == ScalType::ISINT && this->_outOfRange[ScalType::ISINT] == true )
		std::cout << "Couldnt cast from int cause the int was invalid";
	else if ( this->_outOfRange[ScalType::ISFLOAT] == true )
		std::cout << "Out of float's range";
	else {

		std::cout << this->_f;
		double intpart;
		if ( this->_specialFloatValues == false && std::modf( static_cast<double>(this->_f),  &intpart ) == 0. )
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if ( this->_type == ScalType::ISIMPOSSIBLE )
		std::cout << "impossible";
	else if (this->_type == ScalType::ISINT && this->_outOfRange[ScalType::ISINT] == true )
		std::cout << "Couldnt cast from int cause the int was invalid";
	else if ( this->_outOfRange[ScalType::ISDOUBLE] == true )
		std::cout << "Out of double's range";
	else {

		double	intpart;
		std::cout << this->_d;
		if ( this->_specialFloatValues == false && std::modf( this->_d,  &intpart ) == 0. )
			std::cout << ".0";
	}
	std::cout << std::endl;

	return ;
}

void	ScalType::setType() {

	if ( this->_toConv.empty() )
		return ;
	else if ( this->_toConv.length() == 1 && !isdigit( this->_toConv[0] ) ) {

		this->_type = ScalType::ISCHAR;
		this->_c = this->_toConv[0];
		return ;
	}
	else if ( this->_toConv.compare("-inf") == 0 || this->_toConv.compare("inf") == 0 || this->_toConv.compare("nan") == 0 ) {

		this->_type = ScalType::ISDOUBLE;
		this->_d = strtod(this->_toConv.c_str(), NULL);
		this->_f = strtof(this->_toConv.c_str(), NULL);
		this->_specialFloatValues = true;
		return ;
	}
	else if ( this->_toConv.compare("-inff") == 0 || this->_toConv.compare("inff") == 0 || this->_toConv.compare("nanf") == 0 ) {

		this->_type = ScalType::ISFLOAT;
		this->_d = strtod(this->_toConv.c_str(), NULL);
		this->_f = strtof(this->_toConv.c_str(), NULL);
		this->_specialFloatValues = true;
		return ;
	}
	bool	sign = false, dot = false, fl = false, digit = false;
	if ( this->_toConv[0] == '+' || this->_toConv[0] == '-')
		sign = true;
	for ( std::string::iterator it = this->_toConv.begin() + (sign == true); it != this->_toConv.end(); ++it ) {
		if ( *it == '.' && dot == true )
			return ;
		else if ( *it == '.' ) {
			
			dot = true;
			continue ;
		}
		else if ( fl == true || (*it == 'f' && dot == false) )
			return ;
		else if ( *it == 'f' ) {

			fl = true;
			continue ;
		}
		else if ( isdigit(*it) == 0)
			return ;
		else
			digit = true;
	}
	if ( digit == false)
		return ;
	else if ( fl == true ) {

		this->_type = ScalType::ISFLOAT;
		errno = 0;
		this->_f = strtof(this->_toConv.c_str(), NULL);
		if ( errno == ERANGE )
			this->_outOfRange[ScalType::ISFLOAT] = true;
	}
	else if ( dot == true ) {

		this->_type = ScalType::ISDOUBLE;
		errno = 0;
		this->_d = strtod(this->_toConv.c_str(), NULL);
		if ( errno == ERANGE )
			this->_outOfRange[ScalType::ISDOUBLE] = true;
	}
	else {

		this->_type = ScalType::ISINT;
		errno = 0;
		long tmp = strtol(this->_toConv.c_str(), NULL, 10);
		if ( errno == ERANGE || tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max() )
			this->_outOfRange[ScalType::ISINT] = true;
		this->_i = static_cast<int>(tmp);
	}
	return ;
}

void	ScalType::convToChar() {

	if ( this->_type == ScalType::ISCHAR || this->_type == ScalType::ISIMPOSSIBLE )
		return ;
	else if ( this->_i < std::numeric_limits<char>::min() || this->_i  > std::numeric_limits<char>::max() || this->_outOfRange[ScalType::ISINT] == true )
		this->_outOfRange[ScalType::ISCHAR] = true;
	else {

		switch (this->_type) {

			case ScalType::ISINT :
				this->_c = static_cast<char>(this->_i);
				break;
			case ScalType::ISFLOAT :
				this->_c = static_cast<char>(this->_f);
				break;
			case ScalType::ISDOUBLE :
				this->_c = static_cast<char>(this->_d);
				break;
			default :
				break;
		}
		if ( !isprint(this->_c) )
			this->_nonDisplayableChar = true;
	}
	return ;
}

void	ScalType::convToFloat() {

	if ( this->_type == ScalType::ISFLOAT || this->_type == ScalType::ISIMPOSSIBLE || this->_specialFloatValues == true )
		return ;

	errno = 0;
	this->_f = strtof(this->_toConv.c_str(), NULL);
	if ( this->_type != ScalType::ISCHAR && errno == ERANGE )
		this->_outOfRange[ScalType::ISFLOAT] = true;

	switch ( this->_type ) {

		case ScalType::ISINT :
			this->_f = static_cast<float>(this->_i);
			break;
		case ScalType::ISCHAR :
			this->_f = static_cast<float>(this->_c);
			break;
		case ScalType::ISDOUBLE :
			this->_f = static_cast<float>(this->_d);
			break;
		default :
			break;
	}

	return ;
}

void	ScalType::convToDouble() {

	if ( this->_type == ScalType::ISDOUBLE || this->_type == ScalType::ISIMPOSSIBLE || this->_specialFloatValues == true )
		return ;
	errno = 0;
	this->_d = strtod(this->_toConv.c_str(), NULL);
	if ( this->_type != ScalType::ISCHAR && errno == ERANGE )
		this->_outOfRange[ScalType::ISDOUBLE] = true;
	switch ( this->_type ) {

		case ScalType::ISINT :
			this->_d = static_cast<double>(this->_i);
			break;
		case ScalType::ISCHAR :
			this->_d = static_cast<double>(this->_c);
			break;
		case ScalType::ISFLOAT :
			this->_d = static_cast<double>(this->_f);
			break;
		default :
			break;
	}

	return ;
}

void	ScalType::convToInt() {

	if ( this->_type == ScalType::ISINT || this->_type == ScalType::ISIMPOSSIBLE )
		return ;
	errno = 0;
	long tmp = strtol(this->_toConv.c_str(), NULL, 10);
	if ( this->_type != ScalType::ISCHAR && (errno == ERANGE || tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max() ))
		this->_outOfRange[ScalType::ISINT] = true;
	switch ( this->_type ) {

		case ScalType::ISDOUBLE :
			this->_i = static_cast<int>(this->_d);
			break;
		case ScalType::ISCHAR :
			this->_i = static_cast<int>(this->_c);
			break;
		case ScalType::ISFLOAT :
			this->_i = static_cast<int>(this->_f);
			break;
		default :
			break;
	}

	return ;
}

ScalType::ScalType() {

	return ;
}
ScalType::ScalType( ScalType const & src ) {

	(void)src;
	return ;
}

ScalType &	ScalType::operator=( ScalType const & rhs ) {

	(void)rhs;
	return *this;
}
