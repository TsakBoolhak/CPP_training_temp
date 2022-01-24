#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact {

public:

	typedef 	enum e_infos {

		FIRST_NAME = 0,
		LAST_NAME,
		NICK_NAME,
		PHONE_NUMBER,
		DARKEST_SECRET,
		SIZE
	}			t_infos;

	Contact( void );
	~Contact ( void );
	
	void	setInfos( void );
	std::string	getInfo( int index ) const;

private:	

	std::string infos[SIZE];

	int			checkPhoneNumber( std::string number ) const;
	std::string	getField( int index ) const;
	int			setField( std::string name, int index );

};

#endif
