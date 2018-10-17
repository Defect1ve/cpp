#include "span.hpp"

int main()
{
	srand(time(0));
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		Span sp_additional = Span(10000);
		sp_additional.addNumber(sp_additional.begin(), sp_additional.begin() + 10000);
		std::cout << sp_additional.shortestSpan() << std::endl;
		std::cout << sp_additional.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}