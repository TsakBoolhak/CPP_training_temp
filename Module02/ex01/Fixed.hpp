#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public :

	Fixed( void );
	Fixed( Fixed const &src );
	Fixed( const int value);
	Fixed( const float value);
	~Fixed( void );

	int	getRawBits( void ) const;
	int getDecimalPartSize( void );
	int	getDecimalPart( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed &	operator=( Fixed const & rhs );

private :

	int	rawBits;
	static const int	decimalPartSize = 8;

};

std::ostream & operator<<( std::ostream& os, const Fixed& fixedPoint );

#endif
