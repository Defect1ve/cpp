#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>

class	ScavTrap
{
	private:

		std::string		_name;
		unsigned int	_HP;
		unsigned int	_max_HP;
		unsigned int	_EP;
		unsigned int	_max_EP;
		unsigned int	_LVL;
		unsigned int	_melee_damage;
		unsigned int	_range_damage;
		unsigned int	_armor_reduc;
		static std::string const challanges[10];

	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &src);
		ScavTrap & operator=(ScavTrap const &src);
		int			getMeleeAttackDamage();
		int			getRangedAttackDamage();
		int			getHP();
		int			getEP();
		int			getLVL();
		std::string	getName();
		void		increase_LVL();
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challangeNewcomer();
};

#endif