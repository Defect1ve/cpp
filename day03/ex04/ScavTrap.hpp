#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:

		static std::string const challanges[10];

	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &src);
		ScavTrap & operator=(ScavTrap const &src);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		challangeNewcomer();
};

#endif