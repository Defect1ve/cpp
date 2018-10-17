# include "Zombie.hpp"
# include "ZombieEvent.hpp"
# include <iostream>

int 	main(void)
{
	ZombieEvent		event;
	Zombie*			zom;
	Zombie**		array = new Zombie*[5];

	std::cout << "Custom Zombie" << std::endl;
	event.setZombieType("Angry");
	zom = event.newZombie("Andriy");
	zom->announce();
	std::cout << "Random Zombies" << std::endl;
	srand(time(0));
	for (int i = 0; i < 5; i++)
		array[i] = event.randomChamp();
	for (int j = 0; j < 5; j++)
		delete array[j];
	return (0);
}