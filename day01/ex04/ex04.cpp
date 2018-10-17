#include <iostream>

int		main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		&ref = str;
	std::string		*p = &str;

	std::cout << ref << std::endl;// display via reference
	std::cout << *p << std::endl;// display via pointer
}