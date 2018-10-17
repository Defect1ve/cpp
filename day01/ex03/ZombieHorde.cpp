#include "ZombieHorde.hpp"
# include <iostream>

ZombieHorde::ZombieHorde(int n)
{
	_array = new Zombie[n];
	this->array_size = n;
	this->announce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->_array;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->array_size; i++)
		this->_array[i].announce();
}