# include "Bureaucrat.hpp"

int		main()
{
	Bureaucrat a("NameA", -10);
	Bureaucrat b("NameB", 1);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "a:" << std::endl;
	a.decrement();
	std::cout << a << std::endl;
	a.increment();
	std::cout << a << std::endl;
	std::cout << "b:" << std::endl;
	b.decrement();
	std::cout << b << std::endl;
	b.increment();
	std::cout << b << std::endl;
	b.increment();
	std::cout << b << std::endl;
	return (0);
}