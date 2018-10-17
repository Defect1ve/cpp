# include "Warrior.hpp"

Warrior::Warrior(std::string name) : Victim(name)
{
	this->_NAME = name;
	std::cout << "Holy " << _NAME << " is here!" << std::endl;
}

Warrior::Warrior(Warrior const &src) : Victim(src)
{
	*this = src;
	std::cout << "Holy " << _NAME << " is here!" << std::endl;
}

Warrior::~Warrior(void)
{
	std::cout << "Okay, it's time to go to Odin..." << std::endl;
}

void	Warrior::getPolymorphed(void) const
{
	std::cout << _NAME << " has been turned into a tree(it's beautiful, isn't it?) !" << std::endl;
}

Warrior & Warrior::operator=(Warrior const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_NAME = src._NAME;
	return (*this);
}