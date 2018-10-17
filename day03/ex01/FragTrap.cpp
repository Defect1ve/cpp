# include "FragTrap.hpp"

const std::string FragTrap::attacks[10] = {"Muzhickiy punch", "Pero pod rebro", "Nozh v pechen' - nikto ne vechen", "Pacanskaya vertuha", "Truboy po scham", \
"Rogatka", "Harkach", "Nozhichek", "AK-47", "Chetkaya repchina"};

FragTrap::FragTrap(void) : _name("Andron"), _HP(100), _max_HP(100), _EP(100), _max_EP(100), _LVL(1), _melee_damage(30), _range_damage(20), _armor_reduc(5)
{
	std::cout << "Hello world! Ya rodilsya, suchen'ki" << std::endl;
}

FragTrap::FragTrap(std::string name) : _name(name), _HP(100), _max_HP(100), _EP(100), _max_EP(100), _LVL(1), _melee_damage(30), _range_damage(20), _armor_reduc(5)
{
	std::cout << "\033[1;30mBeep beep motherf@ckers! " << name << " rodilsya, suchen'ki\033[0m" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "\033[1;30m" << this->_name << ": Oh no! Is it a blood? Where is the fucking blood? Okay, even my death is so boring...\033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(FragTrap const &src)
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

int		FragTrap::getMeleeAttackDamage(void)
{
	return (this->_melee_damage);
}

int		FragTrap::getRangedAttackDamage(void)
{
	return (this->_range_damage);
}

int		FragTrap::getHP(void)
{
	return (this->_HP);
}

int		FragTrap::getEP(void)
{
	return (this->_EP);
}

int		FragTrap::getLVL(void)
{
	return (this->_LVL);
}

std::string	FragTrap::getName(void)
{
	return (this->_name);
}

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "\033[1;31mFragTrap " << this->_name << " attacks " << target << " with ranged hit\033[0m" << std::endl;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "\033[1;31mFragTrap " << this->_name << " attacks " << target << " with melee hit\033[0m" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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

void		FragTrap::increase_LVL(void)
{
	this->_LVL++;
}

bool		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_EP < 25)
	{
		std::cout << "Sorry, " << this->_name << " is hungry, he need more energy\n" << std::endl;
		return false;
	}
	this->_EP -= 25;
	std::cout << "\033[1;31mFragTrap " << this->_name << " attacks " << target << " using " << attacks[rand() % 10] << "\033[0m" << std::endl;
	return (true);
}