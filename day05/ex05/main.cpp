#include "CentralBureaucracy.hpp"

void		help()
{
	srand(time(0));
	CentralBureaucracy cb;
	std::string	names[10] = {"Jack", "John", "Bill", "Khan", "Oliver", "Itan", "Fabian", "Kevin", "Zak", "Matt"};

	for (int i = 0; i < 20; i++)
		cb.FillBur(Bureaucrat(names[rand() % 10], rand() % 149 + 1));
	for (int j = 0; j < 50; j++)
		cb.queueUp(names[rand() % 10]);
	cb.doBureaucracy();
}

int main()
{
	help();
	system("leaks -q a.out");
	return (1);
}
