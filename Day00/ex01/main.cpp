#include <iostream>
#include <ostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

bool	is_integer(std::string str) {

	std::string::iterator it=str.begin();

	long	nb = 0;
	int		sign = 1;

	for ( ; isspace(*it) ; it++)
		;
	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	for ( ; isdigit(*it) ; it++)
	{
		nb = nb * 10 + *it - '0';
		if (nb * sign > std::numeric_limits<int>::max() || nb * sign < std::numeric_limits<int>::min())
			return 0;
	}
	if (*it || it == str.begin())
		return 0;
	return 1;
}

int	main( void ) {

	PhoneBook phoneBook;
	std::string input;

	do {
		std::cout << "Awaiting order..." << std::endl;
		std::cout << "Available commands : ADD, SEARCH and EXIT" << std::endl;
		std::cout << "Enter a command : ";
		getline(std::cin, input);
		std::cout << std::endl;
		if (std::cin.eof()) {
			std::cout << "End Of File Reached. Program Now Quit" << std::endl;
			return -1;
		}
		if (input.compare("ADD") == 0)
			phoneBook.addUser();
		else if (input.compare("SEARCH") == 0) {
			if (phoneBook.printPhoneBookBriefInfos() == 0) {
				std::cout << std::endl << "Select the index of the user you want details on" << std::endl;
				getline(std::cin, input);
				if (std::cin.eof()) {
					std::cout << "End Of File Reached. Program Now Quit" << std::endl;
					return -1;
				}
				std::cout << std::endl;
				if (is_integer(input))
					phoneBook.printUserInfos(atoi(input.c_str()));
				else
					std::cout << input << " is not a valid index" << std::endl;
				input.clear();
			}
		}
		else if (input.empty())
			std::cout << "Empty command" << std::endl;
		else if (input.compare("EXIT") != 0)
			std::cout << input << " is not a valid command" << std::endl;
		std::cout << std::endl;
	} while (input.compare("EXIT") != 0 && std::cin.eof() == 0);

	return 0;
}
