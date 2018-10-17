# include "FragTrap.hpp"

const std::string FragTrap::attacks[10] = {"Muzhickiy punch", "Pero pod rebro", "Nozh v pechen' - nikto ne vechen", "Pacanskaya vertuha", "Truboy po scham", \
"Rogatka", "Harkach", "Nozhichek", "AK-47", "Chetkaya repchina"};

FragTrap::FragTrap(void)
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
	std::cout << "Hello world! Ya rodilsya, suchen'ki" << std::endl;
}

FragTrap::FragTrap(std::string name)
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

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "\033[1;31mFragTrap " << this->_name << " attacks " << target << " with ranged hit\033[0m" << std::endl;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "\033[1;31mFragTrap " << this->_name << " attacks " << target << " with melee hit\033[0m" << std::endl;
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