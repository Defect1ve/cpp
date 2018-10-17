#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <list>

template<typename T>
typename T::iterator		easyfind(T container, int value)
{
	std::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range();
	return (it);
}

#endif