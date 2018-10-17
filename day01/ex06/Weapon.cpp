#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void)
{ }

Weapon::Weapon(const std::string &str)
{
	this->type = str;
}

void	Weapon::setType(const std::string &str)
{
	this->type = str;
}

std::string	&Weapon::getType(void)
{
	std::string &str = this->type;
	return (str);
}