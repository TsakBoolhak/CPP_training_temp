#include <iostream>
#include <string>
#include "Contact.class.hpp"
#include <iomanip>

Contact::Contact( void ) {

	return ;
}

Contact::~Contact( void ) {

	return ;
}

std::string	Contact::getField( int index ){

	std::string	field (Contact::infos[index]);

	return field;
}

int			Contact::setField( std::string str, int index) {

	if (str.empty()) {
		std::cout << "Error: an empty string was passed as argument" << std::endl;

		return -1;
	}
//	else if (index == PHONE_NUMBER) {
//	;	
//	}
	this->infos[index] = str;
	return 0;
}

void	Contact::setInfos ( void ) {

	std::string input;

	int	index = 0;

	do {
		std::string field;

		switch (index)
		{
			case FIRST_NAME:
				field = "first name";
				break;
			case LAST_NAME:
				field = "last name";
				break;
			case NICK_NAME:
				field = "nick name";
				break;
			case PHONE_NUMBER:
				field = "phone number";
				break;
			case DARKEST_SECRET:
				field = "darkest secret";
				break;
			default:
				field.clear();
				break;
		}
		do {
			std::cout << "What is the " << field  << " of the contact you want to add?" << std::endl;
			getline(std::cin, input);
		}while (Contact::setField(input, index) != 0);
		std::cout << std::endl;
		index++;
	}while (index < SIZE);

	return ;
}

std::string	Contact::getInfo ( int index ) {

	std::string str;
	if (index < FIRST_NAME || index >= SIZE)
		return str;
	str = this->infos[index];
	return str;
}
