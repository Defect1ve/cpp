# include "ScavTrap.hpp"

const std::string ScavTrap::challanges[10] = {"Jump over himself", "Make morning coffee", "Run off for Jack Daniel's", "Clean the garbage", "Run off for whores",\
 "Bring slippers", "Eval Piscine CPP", "Work out the tig", "Train of wasting time", "Make a breakfast"};

ScavTrap::ScavTrap(void) : _name("Andron"), _HP(100), _max_HP(100), _EP(50), _max_EP(50), _LVL(1), _melee_damage(20), _range_damage(15), _armor_reduc(3)
{
	std::cout << "Hello world! Ya rodilsya, suchen'ki" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _HP(100), _max_HP(100), _EP(50), _max_EP(50), _LVL(1), _melee_damage(20), _range_damage(15), _armor_reduc(3)
{
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

int		ScavTrap::getMeleeAttackDamage(void)
{
	return (this->_melee_damage);
}

int		ScavTrap::getRangedAttackDamage(void)
{
	return (this->_range_damage);
}

int		ScavTrap::getHP(void)
{
	return (this->_HP);
}

int		ScavTrap::getEP(void)
{
	return (this->_EP);
}

int		ScavTrap::getLVL(void)
{
	return (this->_LVL);
}

std::string	ScavTrap::getName(void)
{
	return (this->_name);
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "\033[1;31mScavTrap " << this->_name << " attacks " << target << " with ranged hit causes " << this->_range_damage << " damage\033[0m" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "\033[1;31mScavTrap " << this->_name << " attacks " << target << " with melee hit causes " << this->_melee_damage << " damage\033[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
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

void		ScavTrap::increase_LVL(void)
{
	this->_LVL++;
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