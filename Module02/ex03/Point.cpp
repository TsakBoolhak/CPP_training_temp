# include "Point.h"


Point::Point( void ) : x ( 0 ), y ( 0 ) {

	return ;
}

Point::Point( const float xSrc, const float ySrc ) : x ( xSrc ), y ( ySrc ) {

	return ;
}

Point::Point( Point & src ) {

	*this = src;
	return ;
}

Point::~Point( void ) {

	return ;
}

Fixed &	Point::getX( void ) const {

	return this->x;
}

Fixed &	Point::getY( void ) const {

	return this->y;
}

Point &	Point::operator=( Point const & rhs ) {

	if (this != rhs) {

		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

#endif
