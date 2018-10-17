# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "Andron";
	this->_HP = 100;
	this->_max_HP = 100;
	this->_EP = 100;
	this->_max_EP = 100;
	this->_LVL = 1;
	this->_melee_damage = 30;
	this->_range_damage = 20;
	this->_armor_reduc = 5;
	std::cout << "ClapTrap object has been created. Beep" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_HP = 100;
	this->_max_HP = 100;
	this->_EP = 100;
	this->_max_EP = 100;
	this->_LVL = 1;
	this->_melee_damage = 30;
	this->_range_damage = 20;
	this->_armor_reduc = 5;
	std::cout << "ClapTrap object has been created. Beep" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap object has been destroyed. Beep" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap object has been created. Beep" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_HP = src._HP;
	this->_max_HP = src._max_HP;
	this->_EP = src._EP;
	this->_max_EP = src._max_EP;
	this->_LVL = src._LVL;
	this->_melee_damage = src._melee_damage;
	this->_range_damage = src._range_damage;
	this->_armor_reduc = src._armor_reduc;
	return (*this);
}

int		ClapTrap::getMeleeAttackDamage(void)
{
	return (this->_melee_damage);
}

int		ClapTrap::getRangedAttackDamage(void)
{
	return (this->_range_damage);
}

int		ClapTrap::getHP(void)
{
	return (this->_HP);
}

int		ClapTrap::getEP(void)
{
	return (this->_EP);
}

int		ClapTrap::getLVL(void)
{
	return (this->_LVL);
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HP > 0)
	{
		std::cout << "\033[1;34mAgh... " << this->_name << " got " << amount - this->_armor_reduc << " damage. It seems he lost some wheels =(\033[0m\n" << std::endl;
		if (this->_HP < amount - this->_armor_reduc)
			this->_HP = 0;
		else
			this->_HP -= amount - this->_armor_reduc;
	}
	else
	{
		this->_HP = 0;
		std::cout << "Oh no! You just kick the " << this->_name << "'s body. He already lost his HP... R.I.P.\n" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHP())
	{
		std::cout << "\033[1;32m" << this->_name << " feels much better. In the name of Odin. *restores " << amount << " HP and " << amount * 3 << " EP*\033[0m\n" << std::endl;
		if (this->_HP + amount > this->_max_HP)
			this->_HP = this->_max_HP;
		else
			this->_HP += amount;
		if (this->_EP + amount > this->_max_EP)
			this->_EP = this->_max_EP;
		else
			this->_EP += amount * 3;
	}
}

void		ClapTrap::increase_LVL(void)
{
	this->_LVL++;
}
