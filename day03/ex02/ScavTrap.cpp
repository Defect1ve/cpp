# include "ScavTrap.hpp"

const std::string ScavTrap::challanges[10] = {"Jump over himself", "Make morning coffee", "Run off for Jack Daniel's", "Clean the garbage", "Run off for whores",\
 "Bring slippers", "Eval Piscine CPP", "Work out the tig", "Train of wasting time", "Make a breakfast"};

ScavTrap::ScavTrap(void)
{
	this->_name = "Andron";
	this->_HP = 100;
	this->_max_HP = 100;
	this->_EP = 50;
	this->_max_EP = 50;
	this->_LVL = 1;
	this->_melee_damage = 20;
	this->_range_damage = 15;
	this->_armor_reduc = 3;
	std::cout << "Hello world! Ya rodilsya, suchen'ki" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_HP = 100;
	this->_max_HP = 100;
	this->_EP = 50;
	this->_max_EP = 50;
	this->_LVL = 1;
	this->_melee_damage = 20;
	this->_range_damage = 15;
	this->_armor_reduc = 3;
	std::cout << "\033[1;30mBeep beep motherf@ckers! " << name << " rodilsya, suchen'ki\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[1;30m" << this->_name << ": Oh no! Is it a blood? Where is the fucking blood? Okay, even my death is so boring...\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &src)
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

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "\033[1;31mScavTrap " << this->_name << " attacks " << target << " with ranged hit causes " << this->_range_damage << " damage\033[0m" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "\033[1;31mScavTrap " << this->_name << " attacks " << target << " with melee hit causes " << this->_melee_damage << " damage\033[0m" << std::endl;
}

void		ScavTrap::challangeNewcomer(void)
{
	if (this->_EP < 25)
		std::cout << "Sorry, " << this->_name << " is hungry, he need more energy\n" << std::endl;
	else
	{
		this->_EP -= 25;
		std::cout << "\033[1;31mScavTrap " << this->_name << " " << challanges[rand() % 10] << " for 25 EP\033[0m\n" << std::endl;
	}
}