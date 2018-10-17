# include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	this->_NAME = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
	*this = src;
	std::cout << "Zog zog." << std ::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << _NAME << " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_NAME = src._NAME;
	return (*this);
}