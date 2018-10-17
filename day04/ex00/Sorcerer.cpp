# include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
	_NAME = name;
	_TITLE = title;
	std::cout << _NAME << ", " << _TITLE << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const&src)
{
	*this = src;
	std::cout << _NAME << ", " << _TITLE << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << _NAME << ", " << _TITLE << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string	Sorcerer::getName(void) const
{
	return (this->_NAME);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->_TITLE);
}

std::ostream &operator<<(std::ostream & o, Sorcerer const &src)
{
	std::string temp = "";
	temp = "I am " + src.getName() + ", " + src.getTitle() + ", and I like ponies !\n";
	o  << temp;
	return o;
}

void Sorcerer::polymorph(Victim const &src) const
{
	src.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_NAME = src._NAME;
	this->_TITLE = src._TITLE;
	return (*this);
}