#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define CONTACT_LIST_MAXSIZE 8

# include "Contact.class.hpp"

class PhoneBook {

public:

	PhoneBook( void );
	~PhoneBook( void);

	void	addUser( void );
	Contact	getUser( int userIndex );
	int		printUserBriefInfos( int userIndex );
	int		printUserInfos( int userIndex );
	int		printPhoneBookBriefInfos( void );
	int		getSize( void );

private:

	int	size;
	Contact contactList[CONTACT_LIST_MAXSIZE];
	
};
#endif
