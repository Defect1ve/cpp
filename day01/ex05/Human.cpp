#include "Human.hpp"
# include "Brain.hpp"
# include <string>

Human::Human(void) 
{
	this->age = 76;
}

std::string	Human::identify(void)
{
	return (this->brain).identify();
}

const Brain	&Human::getBrain(void)
{
	const Brain	&temp = this->brain;
	return (temp);
}