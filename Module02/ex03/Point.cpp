# include "Point.hpp"


Point::Point( void ) : x ( 0.f ), y ( 0.f ) {

	return ;
}

Point::Point( const float xSrc, const float ySrc ) : x ( xSrc ), y ( ySrc ) {

	return ;
}

Point::Point( Point const & src ) : x ( 0 ), y ( 0 ) {

	*this = src;
	return ;
}

Point::~Point( void ) {

	return ;
}

Fixed	Point::getX( void ) const {

	return this->x;
}

Fixed	Point::getY( void ) const {

	return this->y;
}

Point &	Point::operator=( Point const & rhs ) {

	if (this != &rhs) {

		*(Fixed *)(&this->x) = rhs.x;
		*(Fixed *)(&this->y) = rhs.y;
	}
	return *this;
}
