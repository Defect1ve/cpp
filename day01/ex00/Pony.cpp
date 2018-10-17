#include "Pony.hpp"
# include "iostream"

Pony::Pony(int a, int b)
{
	this->_height = a;
	this->_weight = b;
	std::cout << "Pony has been created with weight: " << this->_weight << " and height: " << this->_height << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "Pony has been died" << std::endl;
}

void	Pony::SayHello()
{
	std::cout << "Ya rodilsya =)" << std::endl;
}