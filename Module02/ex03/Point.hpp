#ifndef POINT_HPP
# define POINT_HPP

class Point {

public :

	Point( void );
	Point( const float xSrc, const float ySrc );
	Point( Point & src);
	~Point( void );

	Fixed &	getX( void ) const;
	Fixed &	getY( void ) const;

	Point &	operator=( Point const & rhs );

private :

	Fixed const	x;
	Fixed const	y;
};

#endif
