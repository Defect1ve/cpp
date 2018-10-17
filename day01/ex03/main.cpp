# include "Zombie.hpp"
# include "ZombieHorde.hpp"
# include <iostream>

int 	main(void)
{
	int			n;
	std::string	str;

	srand(time(0));
	std::cout << "Please, enter number of zombies:" << std::endl;
	if (!(std::cin >> str))
	{
		std::cout << "End of input" << std::endl;
		exit(0);
	}
	n = atoi(str.c_str());
	if (n < 1 || n > 100)
		std::cout << "You must enter number between 1 and 100" << std::endl;
	else
		ZombieHorde horde(n);
	return (0);
}