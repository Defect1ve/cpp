# include "Zombie.hpp"
# include <string>
# include <iostream>

Zombie::~Zombie(void)
{
	std::cout << "Aghhh... Rest in peace, dear zombie " << this->_name << std::endl;
}

void		Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string	Zombie::getName()
{
	return (this->_name);
}

void		Zombie::setName(std::string str)
{
	this->_name = str;
}

std::string	Zombie::getType()
{
	return (this->_type);
}

void		Zombie::setType(std::string str)
{
	this->_type = str;
}