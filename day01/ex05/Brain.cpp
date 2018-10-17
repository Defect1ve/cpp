#include "Brain.hpp"
#include <string>
#include <sstream>

std::string	Brain::identify(void) const
{
	std::stringstream ss;
	ss << this;  
	return (ss.str());
}