#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony *first = new Pony(110, 90);
	first->SayHello();
	delete first;
}

void	ponyOnTheStack()
{
	Pony second = Pony(120, 100);
	second.SayHello();
}

int		main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
}