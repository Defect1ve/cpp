# include "Human.hpp"

int		main()
{
	Human	Adam;
	std::string act[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	std::string tar[3] = {"Sobaka", "Gopnik", "Lyagaviy"};

	srand(time(0));
	for (int i = 0; i < 7; i++)
		Adam.action(act[std::rand() % 3], tar[std::rand() % 3]);
	return (0);
}