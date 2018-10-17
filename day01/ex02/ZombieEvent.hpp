#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP
# include "Zombie.hpp"

class ZombieEvent
{
public:
	void	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	Zombie* randomChamp(void);

private:

	std::string		type;
};
#endif