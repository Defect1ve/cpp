# include "Zombie.hpp"
# include <string>
# include <iostream>

std::string Zombie::names[5] = {"Ann", "Julia", "Kate", "Sara", "Rose"};
std::string Zombie::types[5] = {"Babysitter", "Warrior", "Traveler", "Sysadmin", "Streamer"};

Zombie::Zombie(void) : _name(Zombie::getName(std::rand() % 5)), _type(Zombie::getType(std::rand() % 5))
{ }

Zombie::~Zombie(void)
{
	std::cout << "Aghhh... Rest in peace, dear zombie " << this->_name << std::endl;
}

void		Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string	Zombie::getName(int n)
{
	return (Zombie::names[n]);
}

std::string	Zombie::getType(int n)
{
	return (Zombie::types[n]);
}