# include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	this->_name = "Example";
	this->_HP = FragTrap::_HP;
	this->_max_HP = FragTrap::_max_HP;
	this->_EP = NinjaTrap::_EP;
	this->_max_EP = NinjaTrap::_max_EP;
	this->_LVL = 1;
	this->_melee_damage = NinjaTrap::_melee_damage;
	this->_range_damage = FragTrap::_range_damage;
	this->_armor_reduc = FragTrap::_armor_reduc;
	std::cout << "Hello world! Ya rodilsya, suchen'ki(Super)" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
	this->_name = name;
	this->_HP = FragTrap::_HP;
	this->_max_HP = FragTrap::_max_HP;
	this->_EP = NinjaTrap::_EP;
	this->_max_EP = NinjaTrap::_max_EP;
	this->_LVL = 1;
	this->_melee_damage = NinjaTrap::_melee_damage;
	this->_range_damage = FragTrap::_range_damage;
	this->_armor_reduc = FragTrap::_armor_reduc;
	std::cout << "\033[1;30mBeep beep motherf@ckers! " << name << " rodilsya, suchen'ki\033[0m" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "\033[1;30m" << this->_name << "(Super): Oh no! Is it a blood? Where is the fucking blood? Okay, even my death is so boring...\033[0m" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
	*this = src;
}

SuperTrap & SuperTrap::operator=(SuperTrap const &src)
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

void	SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}

void	SuperTrap::rangedAttack(std::string const &target)
{
	NinjaTrap::rangedAttack(target);
}