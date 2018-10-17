# include "FragTrap.hpp"
# include "ScavTrap.hpp"

bool	they_alive(FragTrap **array)
{
	int i = 0;

	for (int j = 0; j < 5; j++)
		if (array[j]->getHP())
			i++;
	if (i > 1)
		return (true);
	return (false);
}

void	ScavTest(void)
{
	ScavTrap	scav("Lyoha");
	std::cout << "\n\nTesing of ScavTrap:\n\n" << std::endl;
	scav.meleeAttack("pulesos");
	scav.takeDamage(50);
	scav.increase_LVL();
	std::cout << "Lyoha's LVL: " << scav.getLVL() << "\n" << std::endl;
	scav.beRepaired(50);
	scav.challangeNewcomer();
	scav.challangeNewcomer();
	scav.challangeNewcomer();
	scav.beRepaired(50);
	scav.beRepaired(50);
	scav.challangeNewcomer();
	scav.challangeNewcomer();
	scav.challangeNewcomer();
}

int		main()
{
	std::string const names[5] = {"Kolyan", "Bodya", "Sashok", "Stasyan", "Pashok"};
	FragTrap **array = new FragTrap*[5];
	int target;
	int attacker;
	int value;

	srand(time(0));
	for (int i = 0; i < 5; i++)
		array[i] = new FragTrap(names[i]);
	std::cout << std::endl;
	while (they_alive(array))
	{
		target = rand() % 5;
		while ((attacker = rand() % 5) == target)
			;
		if (array[attacker]->getHP() < 15 || array[attacker]->getEP() < 25)
			array[attacker]->beRepaired(rand() % 5 + 1);
		else
		{
			value = rand() % 2;
			if (array[attacker]->getLVL() > 3)
			{
				if (array[attacker]->vaulthunter_dot_exe(names[target]))
					array[target]->takeDamage(rand() % 20 + 30);
			}
			else
			{
				if (value)
				{
					array[attacker]->meleeAttack(names[target]);
					array[target]->takeDamage(array[attacker]->getMeleeAttackDamage());
				}
				else
				{
					array[attacker]->rangedAttack(names[target]);
					array[target]->takeDamage(array[attacker]->getRangedAttackDamage());
				}

			}
		}
		array[attacker]->increase_LVL();
	}
	for (int i = 0; i < 5; i++)
		if (array[i]->getHP())
			std::cout << "\033[1;33m*****************************************************************************\n\
		We have a winner! Congratulations, " << names[i] << "\n*****************************************************************************\033[0m\n" << std::endl;
	for (int i = 0; i < 5; i++)
		delete array[i];
	delete [] array;
	ScavTest();
}