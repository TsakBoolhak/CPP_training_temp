#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

typedef enum e_infos
{
	FIRST_NAME = 0,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
	SIZE
} t_infos;

class Contact {

public:

	Contact( void );
	~Contact ( void );
	
	void	setInfos( void );
	std::string	getInfo( int index );

private:	

	std::string infos[SIZE];

	std::string	getField( int index );
	int			setField( std::string name, int index );
};

#endif
