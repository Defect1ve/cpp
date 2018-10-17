# include <string>
# include "ZombieEvent.hpp"

#include <iostream>

void	ZombieEvent::setZombieType(std::string str)
{
	this->type = str;
}

Zombie*	ZombieEvent::newZombie(std::string str)
{
	Zombie* zom = new Zombie();
	zom->setName(str);
	zom->setType(this->type);
	return (zom);
}

Zombie*	ZombieEvent::randomChamp(void)
{
	std::string names[5] = {"Ann", "Julia", "Kate", "Sara", "Rose"};
	std::string types[5] = {"Babysitter", "Warrior", "Traveler", "Sysadmin", "Streamer"};
	Zombie* rand_zom = new Zombie;
	int rand;

	rand = std::rand() % 5;
	rand_zom->setName(names[rand]);
	rand = std::rand() % 5;
	rand_zom->setType(types[rand]);
	rand_zom->announce();
	return (rand_zom);
}