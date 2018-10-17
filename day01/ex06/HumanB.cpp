#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &str)
{
	this->name = str;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}