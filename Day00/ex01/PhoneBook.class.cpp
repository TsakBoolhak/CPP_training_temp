#include <string>
#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook( void ) {

	PhoneBook::size = 0;

	return ;
};

PhoneBook::~PhoneBook( void ) {

	return ;
};

void 	PhoneBook::addUser( void ) {

	if (PhoneBook::size < CONTACT_LIST_MAXSIZE)
		PhoneBook::size++;
	else {
		std::cout << "Warning: contact list full, had to delete user " << this->contactList[size - 1].getInfo(Contact::FIRST_NAME) << " " << this->contactList[size - 1].getInfo(Contact::LAST_NAME) << std::endl;
	}

	this->contactList[size - 1].setInfos();

	return ;
}

int	PhoneBook::printUserInfos( int userIndex ) {

	if (userIndex < 0 || userIndex >= PhoneBook::getSize()) {

		if (PhoneBook::getSize() == 0)
			std::cout << "PhoneBook is empty" << std::endl;
		else
			std::cout << "Avalaible indexes : [0-" << PhoneBook::getSize() - 1 << "]" << std::endl;

		return -1;
	}
	else {

		int	index = 0;

		while (index < Contact::SIZE) {

			std::string field;

			if (this->contactList[userIndex].getInfo(index).empty()) {

				return -1;
			}

			switch (index)
			{
				case Contact::FIRST_NAME:
					field = "First Name : ";
					break;
				case Contact::LAST_NAME:
					field = "Last Name : ";
					break;
				case Contact::NICK_NAME:
					field = "Nick Name : ";
					break;
				case Contact::PHONE_NUMBER:
					field = "Phone Number : ";
					break;
				case Contact::DARKEST_SECRET:
					field = "Darkest Secret : ";
					break;
				default:
					field.clear();
					break;
			}

			std::cout << field << this->contactList[userIndex].getInfo(index) << std::endl;
			index++;
		}
	}
	
	return 0;
}

int	PhoneBook::printUserBriefInfos( int userIndex ) {

	if (userIndex < 0 || userIndex >= PhoneBook::getSize()) {

		if (PhoneBook::getSize() == 0)
			std::cout << "PhoneBook is empty" << std::endl;
		else
			std::cout << "Avalaible indexes : [0-" << PhoneBook::getSize() - 1 << "]" << std::endl;

		return -1;
	}
	else {

		int			infosIndex = 0;
		std::string	str;

		std::cout << std::setw(10) << userIndex;
		std::cout << "|";
		while (infosIndex <= Contact::NICK_NAME) {

			str = this->contactList[userIndex].getInfo(infosIndex);
			if (str.empty()) {

				std::cout << "Field is empty" << std::endl;

				return -1;
			}
			str = str.substr(0, 10);
			if (str.length() == 10)
				str[9] = '.';
			std::cout << std::right;
			std::cout << std::setw(10) << str;
			if (infosIndex < Contact::NICK_NAME)
				std::cout << "|";
			infosIndex++;
		}
		std::cout << std::endl;
	}

	return 0;
}

int	PhoneBook::printPhoneBookBriefInfos( void ) {
	int	index = 0;

	 do {
		if (this->printUserBriefInfos(index) != 0)
			return -1;
		index++;
	} while (index < this->size);
	return 0;
}

int		PhoneBook::getSize( void ) {

	return this->size;
}

Contact	PhoneBook::getUser( int userIndex ) {

	Contact user;
	std::string	str;

	if (userIndex < 0 || userIndex >= this->getSize()) {
		return user;
	}
	return this->contactList[userIndex];
}
