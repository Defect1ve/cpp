# include <iostream>
# include <limits>
# include <iomanip>
# include <float.h>
# include <cmath>

int		main(int ac, char **av)
{
	long double	tmp = 0.0;
	if (ac != 2)
		std::cout << "invalid number of parameters" << std::endl;
	else
	{
		try
		{
			if ((av[1][0] > '9' || av[1][0] < '0') && av[1][0] != '-' && av[1][0] != '+')
				tmp = 0;
			else
				tmp = std::stold(av[1]);
			std::cout << "char: ";
			if (tmp < 0 || tmp > 127)
				std::cout << "imposssible" << std::endl;
			else if (tmp < 32.0)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "\'" << static_cast<char>(tmp) << "\'" << std::endl;
			std::cout << "int: ";
			if (static_cast<long int>(tmp) <= INT_MAX && static_cast<long int>(tmp) >= INT_MIN)
				std::cout << static_cast<int>(tmp >= 0 ? tmp + 0.5 : tmp - 0.5) << std::endl;
			else
				std::cout << "impossible" << std::endl;
			std::cout << "float: ";
			if ((static_cast<long double>(tmp) != std::numeric_limits<double>::infinity() && static_cast<float>(tmp) == std::numeric_limits<double>::infinity()) ||
			(static_cast<long double>(tmp) != -std::numeric_limits<double>::infinity() && static_cast<float>(tmp) == -std::numeric_limits<double>::infinity()))
				std::cout << "impossible" << std::endl;
			else
			{
				if (static_cast<float>(tmp) - static_cast<long int>(tmp) == 0)
						std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
				std::cout << static_cast<float>(tmp) << "f" << std::endl;
				std::cout << std::resetiosflags(std::ios::fixed);
			}
			std::cout << "double: ";
			if ((static_cast<long double>(tmp) != std::numeric_limits<double>::infinity() && static_cast<double>(tmp) == std::numeric_limits<double>::infinity()) ||
			(static_cast<long double>(tmp) != -std::numeric_limits<double>::infinity() && static_cast<double>(tmp) == -std::numeric_limits<double>::infinity()))
				std::cout << "impossible" << std::endl;
			else
			{
				if (static_cast<double>(tmp) - static_cast<long int>(tmp) == 0)
					std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
				std::cout << static_cast<double>(tmp) << std::endl;
				std::cout << std::resetiosflags(std::ios::fixed);
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}