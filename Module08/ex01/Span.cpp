#include "Span.hpp"
#include <vector> // used for std::vector<int> operations
#include <algorithm> // used for std::min(), std::max() and std::sort()
#include <utility> // used for std::pair
#include <limits> // used for numeric_limits<unsigned int>::max()

const char *	Span::FullException::what() const throw() {

	return "No space left to add an element";
}

const char *	Span::NoSpanPossible::what() const throw() {

	return "Not enough values to have a span";
}

Span::Span() : _vec ( std::vector<int>() ), _size ( 0 ), _maxSize ( 0 ) {

	return ;
}

Span::Span( unsigned int N ) : _vec ( std::vector<int>() ), _size ( 0 ), _maxSize ( N ) {

	return ;
}

Span::Span( Span const & src ) : _vec ( std::vector<int>() ), _size ( 0 ), _maxSize ( 0 ) {

	*this = src;

	return ;
}

Span::~Span() {

	return ;
}

Span &	Span::operator=( Span const & rhs ) {

	if ( this != &rhs ) {

		this->_vec = rhs._vec;
		this->_size = rhs._size;
		this->_maxSize = rhs._maxSize;
	}

	return *this;
}

void	Span::addNumber( int value ) {

	if ( this->_size == this->_maxSize )
		throw Span::FullException();
	this->_vec.push_back( value );
	std::sort( this->_vec.begin(), this->_vec.end() );
	this->_size++;

	return ;
}

unsigned int	Span::shortestSpan() {

	if ( this->_size < 2 )
		throw Span::NoSpanPossible();

	unsigned int	span = std::numeric_limits<unsigned int>::max();

	for ( std::vector<int>::iterator it = this->_vec.begin() + 1 ; it != this->_vec.end() ; ++it ) {

		std::pair<int, int>	minMax(std::min( *it, *(it - 1) ), std::max( *it, *(it - 1) ) );
		unsigned int	tmp = static_cast<unsigned int>(minMax.second - minMax.first);
		if ( tmp < span )
			span = tmp;
	}

	return span;
}

unsigned int	Span::longestSpan() {

	if ( this->_size < 2 )
		throw Span::NoSpanPossible();

	return *( this->_vec.rbegin() ) - *( this->_vec.begin() );
}
