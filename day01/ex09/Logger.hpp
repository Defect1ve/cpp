#ifndef LOGGER_HPP
# define LOGGER_HPP
# include <string>

class Logger
{
	public:

		Logger(std::string FileName);
		void		log(std::string const & dest, std::string const & message);

	private:

		std::string	FileName;
		void		logToConsole(const std::string &str);
		void		logToFile(const std::string &str);
		std::string	makeLogEntry(const std::string &str);
};

#endif