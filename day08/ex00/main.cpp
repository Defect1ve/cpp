# include "easyfind.hpp"

int		main()
{
	std::list<int>	lst;

	lst.push_back(10);
	lst.push_back(11);
	lst.push_back(12);
	lst.push_back(13);
	lst.push_back(14);
	lst.push_back(15);
	try
	{
		std::cout << *easyfind(lst, 9) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "There is no member with such value in that container" << std::endl;
	}
	try
	{
		std::cout << *easyfind(lst, 11) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "There is no member with such value in that container" << std::endl;
	}
}