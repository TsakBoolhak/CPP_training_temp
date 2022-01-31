#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen {

public :

	Karen( void );
	~Karen( void );

	void	complain( std::string level );

private :
	typedef void (Karen::*memberFuncPtr)( void );

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	unknown( void );
	memberFuncPtr array[5]; 

};

#endif
