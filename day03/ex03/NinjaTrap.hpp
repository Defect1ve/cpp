#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap
{
	public:

		NinjaTrap();
		NinjaTrap(std::string name);
		~NinjaTrap();
		NinjaTrap(NinjaTrap const &src);
		NinjaTrap & operator=(NinjaTrap const &src);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		ninjaShoebox(FragTrap &obj);
		void		ninjaShoebox(ScavTrap &obj);
		void		ninjaShoebox(NinjaTrap &obj);
};

#endif