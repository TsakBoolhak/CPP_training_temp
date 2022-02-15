#include "Point.hpp"
#include "Fixed.hpp"

Fixed	getSign( Point const p1, Point const p2, Point const p3) {

	Fixed	ret;

	ret = ( p1.getX() - p3.getX() ) * ( p2.getY() - p3.getY() ) - ( p2.getX() - p3.getX() ) * ( p1.getY() - p3.getY() );
	return ret;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	bool	hasNeg, hasPos;
	Fixed	d1, d2, d3;

	d1 = getSign(point, a, b);
	d2 = getSign(point, b, c);
	d1 = getSign(point, c, a);

	if ( d1 == 0 || d2 == 0 || d2 == 0 )
		return false;

	hasNeg = d1 < 0 || d2 < 0 || d3 < 0;
	hasPos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(hasNeg && hasPos);
}
