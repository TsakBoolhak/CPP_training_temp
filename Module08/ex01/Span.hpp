#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span {

	public :

		class FullException : public std::exception {

			virtual const char *	what() const throw();
		};

		class NoSpanPossible : public std::exception {

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

		template< class InputIterator >
		void	insertSequence( InputIterator first, InputIterator last ) {

			if ( static_cast< unsigned int >( last - first ) > this->_maxSize - this->_size )
				throw Span::FullException();

			this->_vec.insert(this->_vec.end(), first, last);
			this->_size += static_cast<unsigned int>( last - first );
			std::sort( this->_vec.begin(), this->_vec.end() );

			return ;
		}

	private :

		std::vector<int> _vec;
		std::size_t	_size;
		std::size_t	_maxSize;

};

#endif
