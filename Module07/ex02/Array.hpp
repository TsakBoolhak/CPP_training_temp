#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T >
class Array {

	public :

		class OutOfRangeException : public std::exception {

			public :

				virtual const char *	what() const throw() {

					return "Accessing an invalid index of the array";
				}
		};

		Array() : _size ( 0 ), _arr ( new T[0]() ) {

			return ;
		}

		Array( unsigned int n ) : _size ( n ), _arr ( new T[n]() ) {

			return ;
		}

		Array( Array const & src ) : _size ( 0 ), _arr ( NULL ) {

			*this = src;

			return ;
		}

		~Array() {

			delete [] this->_arr;

			return ;
		}

		Array &	operator=( Array const & rhs ) {

			if ( this != &rhs ) {

				delete [] this->_arr;
				this->_arr = new T[rhs._size];
				this->_size = rhs._size;
				for ( unsigned int i = 0 ; i < this->_size ; ++i )
					this->_arr[i] = rhs._arr[i];
			}

			return *this;
		}

		T &	operator[]( unsigned int n ) const {

			if ( n >= this->_size )
				throw Array::OutOfRangeException();

			return this->_arr[n];
		}

		unsigned int	size() const {

			return this->_size;
		}

	private :

		unsigned int	_size;
		T *				_arr;

};

#endif
