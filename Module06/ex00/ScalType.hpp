#ifndef SCALTYPE_HPP
# define SCALTYPE_HPP

# include <string>

class ScalType {

	public :

				ScalType( char const * str );
				~ScalType();

		void	displayConversions() const;

	private :

		typedef enum e_type {

			ISCHAR = 0,
			ISINT,
			ISFLOAT,
			ISDOUBLE,
			ISIMPOSSIBLE
		}		t_type;

		void	setType();
		void	convToChar();
		void	convToFloat();
		void	convToDouble();
		void	convToInt();
				ScalType();
				ScalType( ScalType const & src );
				ScalType &	operator=( ScalType const & rhs );

		std::string	_toConv;
		t_type		_type;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		bool		_outOfRange[4];
		bool		_nonDisplayableChar;
		bool		_specialFloatValues;
};

#endif
