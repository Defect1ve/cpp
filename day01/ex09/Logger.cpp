# include "Logger.hpp"
# include <ctime>
# include <fstream>
# include <iostream>

Logger::Logger(std::string FileName)
{
	this->FileName = FileName;
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	std::string	dests[2] = {"logToConsole", "logToFile"};
	typedef void	(Logger::*Action)(const std::string &str);
	Action	act[2] = {&Logger::logToConsole, &Logger::logToFile};

	for (int i = 0; i < 2; i++)
		if (dests[i] == dest)
			(this->*(act[i]))(message);
}

void		Logger::logToConsole(const std::string &str)
{
	std::cout << makeLogEntry(str) << std::endl;
}

void		Logger::logToFile(const std::string &str)
{
	std::ofstream	ofs(this->FileName, std::ofstream::out | std::ofstream::app);

	ofs << makeLogEntry(str) << std::endl;
	ofs.close();
}

std::string	Logger::makeLogEntry(const std::string &str)
{
	time_t		rawtime;
	std::string	temp = "";
	std::string	help = "";
	
	time(&rawtime);
	help = (std::string)ctime(&rawtime);
	temp = (std::string)"[" + help.substr(0, help.length() - 1) + (std::string)"] " + str;
	return (temp);
}