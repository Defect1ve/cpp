#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class	ClapTrap
{
	protected:

		std::string		_name;
		unsigned int	_HP;
		unsigned int	_max_HP;
		unsigned int	_EP;
		unsigned int	_max_EP;
		unsigned int	_LVL;
		unsigned int	_melee_damage;
		unsigned int	_range_damage;
		unsigned int	_armor_reduc;

	public:

		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap const &src);
		ClapTrap & operator=(ClapTrap const &src);
		int			getMeleeAttackDamage();
		int			getRangedAttackDamage();
		int			getHP();
		int			getEP();
		int			getLVL();
		std::string	getName();
		void		increase_LVL();
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif