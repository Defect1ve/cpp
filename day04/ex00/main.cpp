# include "Sorcerer.hpp"
# include "Peon.hpp"
# include "Warrior.hpp"

int		main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Warrior jack("Jack");
	std::cout << robert << jim << joe << jack;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(jack);
	return 0;
}