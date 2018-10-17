#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int>	_v;
public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &src);
	~Span();
	void	addNumber(int);
	void	addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);
	std::vector<int>::iterator begin(void);
};

#endif