#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public :

	Point( void );
	Point( const float xSrc, const float ySrc );
	Point( Point const & src);
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

	Point &	operator=( Point const & rhs );

private :

	Fixed const	x;
	Fixed const	y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
