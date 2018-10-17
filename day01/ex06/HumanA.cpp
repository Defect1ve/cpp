#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &str, Weapon &weapon) : name(str), weapon(weapon)
{ }

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}