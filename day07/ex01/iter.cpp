#include <iostream>

void	print_int(int i)
{
	std::cout << i;
}

void	print_char(char c)
{
	std::cout << c;
}

template<typename A, typename L, typename F>
void	iter(A addr, L length, F func)
{
	for (L i = 0; i < length; i++)
		func(addr[i]);
}

int		main(void)
{
	char	str[12] = "hello world";
	int		mass[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	iter(str, 11, print_char);
	std::cout << std::endl;
	iter(mass, 10, print_int);
	std::cout << std::endl;
}