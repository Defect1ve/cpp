#include "span.hpp"

Span::Span(void)
{ }

Span::~Span(void)
{ }

Span::Span(unsigned int n)
{
	_v.reserve(n);
}

std::vector<int>::iterator Span::begin(void)
{
	return (_v.begin());
}

void	Span::addNumber(int value)
{
	if (_v.size() < _v.capacity())
		_v.push_back(value);
	else
		throw std::out_of_range("Container is full");
}

void	Span::addNumber(std::vector<int>::iterator ft, std::vector<int>::iterator st)
{
	if (std::distance(ft, _v.end()) <= std::distance(st, _v.end()))
		throw std::out_of_range("Invalid order of iterators");
	for (; ft != st; ft++)
		_v.insert(ft, rand() % 100 + 1);
}

unsigned int	Span::shortestSpan(void)
{
	if (_v.size() < 2)
		throw std::out_of_range("Not enough elements");
	int min = abs(*(_v.begin()) - *(--_v.end()));
	std::vector<int>::iterator ft;
	std::vector<int>::iterator st;
	for (ft = _v.begin(); ft < _v.end(); ft++)
		for (st = _v.begin(); st < _v.end(); st++)
			if (abs(*ft - *st) < min && ft != st)
				min = abs(*ft - *st);
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (_v.size() < 2)
		throw std::out_of_range("Not enough elements");
	return (*(std::max_element(_v.begin(), _v.end())) - *(std::min_element(_v.begin(), _v.end())));
}