#include "Logger.hpp"

int		main()
{
	Logger log("test");
	std::string		values[2] = {"logToConsole", "logToFile"};

	srand(time(0));
	for (int i = 0; i < 6; i++)
		log.log(values[rand() % 2], "The cake is a lie");
	return (0);
}