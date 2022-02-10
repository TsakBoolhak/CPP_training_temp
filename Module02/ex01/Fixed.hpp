#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public :

	Fixed( void );
	Fixed( Fixed &src );
	Fixed( const int value);
	~Fixed( void );

	int	getRawBits( void ) const;
	int getDecimalPartSize( void );
	void	setRawBits( int const raw);

	Fixed &	operator=( Fixed const & rhs );

private :

	int	rawBits;
	static const int	decimalPartSize = 8;

};

#endif
