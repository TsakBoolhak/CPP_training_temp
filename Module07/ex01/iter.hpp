#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T >
void	iter( T *arr, size_t size, void (*func)( T & ) ) {

	for ( size_t i = 0 ; i < size ; ++i ) {

		func( arr[i] );
	}

	return ;
}

template< typename T >
void	printValue( T const & value) {

	std::cout << value << std::endl;

	return ;
}

template< typename T >
void	resetValue( T & value );

template< typename T >
void	resetValue( T & value ) {

	value = 0;

	return ;
}

template<>
void	resetValue< std::string >( std::string & value ) {

	value = "";

	return ;
}

#endif
