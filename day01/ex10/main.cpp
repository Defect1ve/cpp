#include <iostream>
#include <fstream>
#include <sstream>
# include <cstdio>

int		main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::stringstream ss;
	std::string		buf;

	if (argc == 1)
	{
		ss << std::cin.rdbuf();
		buf = ss.str();
		std::cout << buf;
	}
	for (int i = 1; i < argc; i++)
	{
		if ((std::string)argv[i] == (std::string)"-")
		{
			while(std::cout << std::cin.rdbuf())
			{			
				std::cin.clear();
				std::cout.clear();
				std::freopen(NULL, "r", stdin);
				std::freopen(NULL, "w", stdout);
				break;
			}
		}
		else
		{
			ifs.open(argv[i]);
			ss << ifs.rdbuf();
			buf = ss.str();
			std::cout << buf;
			ifs.close();
		}
		if (errno)
			std::cerr << "./cato9tails: " << argv[i] << " " << std::strerror(errno) << std::endl;
	}
	return (0);
}