# include "main.hpp"

Base::~Base()
{ }

Base * generate(void)
{
	int n = rand() % 3;
	Base *base;
	A		*a;
	B		*b;
	C		*c;

	if (!n)
	{
		a = new A();
		base = static_cast<Base *>(a);
		std::cout << "original: A\nidentify: ";
	}
	else if (n == 1)
	{
		b = new B();
		base = static_cast<Base *>(b);
		std::cout << "original: B\nidentify: ";
	}
	else
	{
		c = new C();
		base = static_cast<Base *>(c);
		std::cout << "original: C\nidentify: ";
	}
	return (base);
}

void identify_from_pointer( Base * p )
{
	if (A* a = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (B* b = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (C* c = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p )
{
	if (A* a = dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (B* b = dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (C* c = dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int 	main(void)
{
	srand(time(0));
	std::cout << "By pointers:" << std::endl;
	for (int i = 0; i < 5; i++)
		identify_from_pointer(generate());
	std::cout << "By reference:" << std::endl;
	for (int i = 0; i < 5; i++)
		identify_from_reference(*(generate()));
}