# include "SuperTrap.hpp"

int		main()
{
	SuperTrap	super("Winner");
	NinjaTrap	frag;

	super.vaulthunter_dot_exe("Scovorodka");
	super.ninjaShoebox(frag);
	super.meleeAttack("Vorona");
	super.rangedAttack("Derevo");
	std::cout << "EP: " << super.getEP() << " HP: " << super.getHP() << " Melee Attack Damage: " << super.getMeleeAttackDamage() << " Ranged Attack Damage: " << super.getRangedAttackDamage() << std::endl;
	super.increase_LVL();
}