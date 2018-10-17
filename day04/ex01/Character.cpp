# include "Character.hpp"

Character::Character(std::string const &name) : _NAME(name), _AP(40), _WEAPON(NULL)
{ }

Character::~Character(void)
{ }

Character::Character(Character const &src)
{
	*this = src;
}

Character & Character::operator=(Character const &src)
{
	this->_NAME = src._NAME;
	this->_AP = src._AP;
	this->_WEAPON = src._WEAPON;
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_NAME);
}

AWeapon*			Character::getWeapon() const
{
	return (this->_WEAPON);
}

unsigned int		Character::getAP() const
{
	return(this->_AP);
}

std::ostream &operator<<(std::ostream & o, Character const &src)
{
	o << src.getName() << " has " << src.getAP() << " AP";
	if (src.getWeapon() != NULL)
		o << " and wields a " << (src.getWeapon())->getName() << "\n";
	else
		o << " and is unarmed\n";
	return o;
}

void Character::recoverAP(void)
{
	if (_AP > 30)
		_AP = 40;
	else
		_AP += 10;
}
void Character::equip(AWeapon* weapon)
{
	this->_WEAPON = weapon;
}
void Character::attack(Enemy* enemy)
{
	unsigned int AP =  this->getWeapon()->getAPCost();

	if (getWeapon() != NULL && enemy != NULL)
	{
		std::cout << _NAME << " attacks " << enemy->getType() << " with a " << getWeapon()->getName() << std::endl;
		if (_AP >= AP)
		{
			_AP -= AP;
			enemy->takeDamage(this->getWeapon()->getDamage());
			this->getWeapon()->attack();
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
}