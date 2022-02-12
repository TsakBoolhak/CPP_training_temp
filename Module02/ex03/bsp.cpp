#include "Point.hpp"
#include "Fixed.hpp"

/*float sign (fPoint p1, fPoint p2, fPoint p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}*/

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

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}
