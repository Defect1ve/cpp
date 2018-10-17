#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
# include "NinjaTrap.hpp"

class	SuperTrap : public NinjaTrap, public FragTrap
{
	public:

		SuperTrap();
		SuperTrap(std::string name);
		~SuperTrap();
		SuperTrap(SuperTrap const &src);
		SuperTrap & operator=(SuperTrap const &src);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
};

#endif