#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	this->_name = "Andron";
	this->_HP = 60;
	this->_max_HP = 60;
	this->_EP = 120;
	this->_max_EP = 120;
	this->_LVL = 1;
	this->_melee_damage = 60;
	this->_range_damage = 5;
	this->_armor_reduc = 0;
	std::cout << "Hello world! Ya rodilsya, suchen'ki(Ninja)" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
	this->_name = name;
	this->_HP = 60;
	this->_max_HP = 60;
	this->_EP = 120;
	this->_max_EP = 120;
	this->_LVL = 1;
	this->_melee_damage = 60;
	this->_range_damage = 5;
	this->_armor_reduc = 0;
	std::cout << "\033[1;30mBeep beep motherf@ckers! " << name << " rodilsya, suchen'ki\033[0m" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "\033[1;30m" << this->_name << "(Ninja): Oh no! Is it a blood? Where is the fucking blood? Okay, even my death is so boring...\033[0m" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &src)
{
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

void	NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "\033[1;31mNinjaTrap " << this->_name << " attacks " << target << " with ranged hit causes " << this->_range_damage << " damage\033[0m" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "\033[1;31mNinjaTrap " << this->_name << " attacks " << target << " with melee hit causes " << this->_melee_damage << " damage\033[0m" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &obj)
{
	std::cout << "NinjaTrap attacks FlapTrap " << obj.getName() << " with nunchuck, then take a tea break and do hara-kiri with traditional Chinese music\n" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &obj)
{
	std::cout << "NinjaTrap attacks ScavTrap " << obj.getName() << " with nunchuck, then take a tea break and do hara-kiri with traditional Chinese music\n" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &obj)
{
	std::cout << "NinjaTrap attacks NinjaTrap " << obj.getName() << " with nunchuck, then take a tea break and do hara-kiri with traditional Chinese music\n" << std::endl;
}