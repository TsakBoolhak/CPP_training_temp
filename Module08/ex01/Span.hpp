#ifndef SPAN_HPP
# define SPAN_HPP

class Span {

	public :

		class FullException : public std:exception {

			virtual const char *	what() const throw();
		};

		class NoSpanPossible : public std:exception {

			virtual const char *	what() const throw();
		};

		Span();
		Span( unsigned int N );
		Span( Span const & src );
		~Span();

		Span &	operator=( Span const & rhs );

		void			addNumber( int value );
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	private :

		std::vector<int> _vec;
		size_t	size;

};

#endif
