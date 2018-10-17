# include "Victim.hpp"

Victim::Victim(std::string name)
{
	_NAME = name;
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _NAME << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const &src)
{
	*this = src;
	std::cout << "Some random victim called " << _NAME << " just popped !" << std::endl;
}

std::string	Victim::getName(void) const
{
	return (this->_NAME);
}

std::ostream &operator<<(std::ostream & o, Victim const &src)
{
	std::string temp = "";
	temp = "I'm " + src.getName() + " and I like otters !\n";
	o  << temp;
	return o;
}

void	Victim::getPolymorphed(void) const
{
	std::cout << _NAME << " has been turned into a cute little sheep !" << std::endl;;
}

Victim & Victim::operator=(Victim const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_NAME = src._NAME;
	return (*this);
}