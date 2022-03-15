#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>

class Data {

	public :

					Data();
					Data( int const i, float const f, std::string const & str );
					Data( Data const & src );
					~Data();

		int			getInt() const;
		float		getFloat() const;
		std::string	getString() const;
		void		setInt( int const i );
		void		setFloat( float const f );
		void		setString( std::string const & str );
		Data &		operator=( Data const & rhs );

	private :

		int			_someInt;
		float		_someFloat;
		std::string	_someString;
};

std::ostream &	operator<<(std::ostream & os, Data const & rhs);

#endif
