#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

void	help(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* jack = new TacticalMarine;
	ISpaceMarine* temp1 = new AssaultTerminator;
	ISpaceMarine* temp = new AssaultTerminator;
	ISpaceMarine* bill = new AssaultTerminator(*temp);
	*temp = *temp1;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(bill);
	vlc->push(jack);
	vlc->push(temp1);
	vlc->push(temp);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
}

int main()
{
	help();
	//system("leaks -q a.out");
	return 0;
}