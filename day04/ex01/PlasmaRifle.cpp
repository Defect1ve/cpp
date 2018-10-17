# include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{ }

PlasmaRifle::~PlasmaRifle()
{ }

void	PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src)
{ }

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const &src)
{
	*((AWeapon *)this) = src;
	return (*this);
}