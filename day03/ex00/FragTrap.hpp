# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>

class	FragTrap
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
		static std::string const attacks[10];

	public:

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &src);
		FragTrap & operator=(FragTrap const &src);
		int			getMeleeAttackDamage();
		int			getRangedAttackDamage();
		unsigned int			getHP();
		unsigned int			getEP();
		unsigned int			getLVL();
		std::string	getName();
		void		increase_LVL();
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		bool		vaulthunter_dot_exe(std::string const & target);
};

#endif