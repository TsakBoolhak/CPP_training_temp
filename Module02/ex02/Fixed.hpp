#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public :

	Fixed( void );
	Fixed( const Fixed &src );
	Fixed( const int value);
	Fixed( const float value);
	~Fixed( void );

	int	getRawBits( void ) const;
	int getDecimalPartSize( void );
	int	getDecimalPart( void) const;
	void	setRawBits( int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed &	min( Fixed & a, Fixed & b );
	static Fixed &	max( Fixed & a, Fixed & b );
	static Fixed const &	min( Fixed const & a, Fixed const & b );
	static Fixed const &	max( Fixed const & a, Fixed const & b );

	Fixed &	operator=( Fixed const & rhs );

	bool	operator>( Fixed const & rhs );
	bool	operator<( Fixed const & rhs );
	bool	operator>=( Fixed const & rhs );
	bool	operator<=( Fixed const & rhs );
	bool	operator==( Fixed const & rhs );
	bool	operator!=( Fixed const & rhs );

	Fixed operator+( Fixed const & rhs );
	Fixed operator-( Fixed const & rhs );
	Fixed operator*( Fixed const & rhs );
	Fixed operator/( Fixed const & rhs );

	Fixed &	operator++( void );
	Fixed 	operator++( int );
	Fixed &	operator--( void );
	Fixed 	operator--( int );

private :

	int	rawBits;
	static const int	decimalPartSize = 8;

};

std::ostream & operator<<( std::ostream& os, const Fixed& fixedPoint );

#endif
