# include "NinjaTrap.hpp"

int		main()
{
	NinjaTrap	ninja("Potap");
	NinjaTrap	Ninja("Orest");
	FragTrap	flag("Ostap");
	ScavTrap	scav("Omel'ko");

	std::cout << "\nOkay, Potap level is " << ninja.getLVL() << "\n" << std::endl;
	ninja.ninjaShoebox(Ninja);
	ninja.ninjaShoebox(flag);
	ninja.ninjaShoebox(scav);
	ninja.meleeAttack("shvabra");
	ninja.takeDamage(40);
}