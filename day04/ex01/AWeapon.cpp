#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_NAME = name;
	this->_APCOST = apcost;
	this->_DAMAGE = damage;
}

AWeapon::~AWeapon(void)
{ }

AWeapon::AWeapon(AWeapon const&src)
{
	*this = src;
}

AWeapon & AWeapon::operator=(AWeapon const &src)
{
	this->_NAME = src._NAME;
	this->_APCOST = src._APCOST;
	this->_DAMAGE = src._DAMAGE;
	return (*this);
}

std::string const &AWeapon::getName() const
{
	return (this->_NAME);
}

int AWeapon::getAPCost() const
{
	return (this->_APCOST);
}

int AWeapon::getDamage() const
{
	return (this->_DAMAGE);
}