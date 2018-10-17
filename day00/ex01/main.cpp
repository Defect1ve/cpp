#include "Contact.hpp"
#include "PhoneBook.hpp"
# include <iostream>

int		main()
{
	std::string		command;

	PhoneBook book;
	while (1)
	{
		if (!std::getline(std::cin, command))
			exit(0);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			book.add();
		else if (command == "SEARCH")
			book.search();
	}
	return (0);
}