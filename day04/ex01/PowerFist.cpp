# include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{ }

PowerFist::~PowerFist()
{ }

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src)
{ }

PowerFist & PowerFist::operator=(PowerFist const &src)
{
	*((AWeapon *)this) = src;
	return (*this);
}