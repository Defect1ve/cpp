# include <iostream>

template<typename T>
void		swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const & min(T const &a, T const &b)
{
	return ((a >= b) ? b : a);
}

template<typename T>
T const & max(T const &a, T const &b)
{
	return ((a <= b) ? b : a);
}

int		main(void)
{
	std::cout << "swap:" << std::endl;
	int a = 31;
	int b = 12;
	std::cout << "int a: " << a << " int b: " << b << std::endl; 
	swap<int>(a, b);
	std::cout << "int a: " << a << " int b: " << b << std::endl;
	char c = 'a';
	char d = '*';
	std::cout << "char a: " << c << " char b: " << d << std::endl; 
	swap<char>(c, d);
	std::cout << "char a: " << c << " char b: " << d << std::endl;
	std::cout << "min:" << std::endl;
	std::cout << min<int>(a, b) << std::endl;
	std::cout << static_cast<char>(min<int>(c, d)) << std::endl;
	std::cout << "max:" << std::endl;
	std::cout << max<int>(a, b) << std::endl;
	std::cout << static_cast<char>(max<int>(c, d)) << std::endl;
	return (0);
}