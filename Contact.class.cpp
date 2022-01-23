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

int	checkPhoneNumber(std::string number)
{
	std::string::iterator it=number.begin();
	int	digitCount = 0, maxDigits = 11, minDigits = 8;

	if (*it == '+') {
		maxDigits = 14;
		minDigits = 9;
		it++;
	}

	for ( ; isdigit(*it) ; it++)
		digitCount++;

	if (*it != '\0')
		return -3;
	else if (digitCount < minDigits)
		return -4;
	else if (digitCount > maxDigits)
		return -5;
	else
		return 0;
}

int			Contact::setField( std::string str, int index) {

	if (str.empty()) {
		std::cout << "Error: Cannot add an empty field" << std::endl;

		return -1;
	}
	else if (index < 0 || index >= SIZE) {
		std::cout << "Error: Invalid index (" << index << ")" << std::endl;

		return -2;
	}
	else if (index == PHONE_NUMBER) {
		int	check = checkPhoneNumber(str);
		if (check != 0)
			std::cout << "Invalid phone number";
		switch (check) {
			case 0:
				break ;
			case -3:
				std::cout << " : contain invalid characters" << std::endl;
				break ;
			case -4:
				std::cout << " : number is too small" << std::endl;
				break ;
			case -5:
				std::cout << " : number is too big" << std::endl;
				break ;
			default:
				std::cout << std::endl;
				break ;
		}
		if (check != 0)
			return (check);
	}
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
			if (std::cin.eof())
				return;
			std::cout << std::endl;
		} while (this->setField(input, index) != 0);
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
