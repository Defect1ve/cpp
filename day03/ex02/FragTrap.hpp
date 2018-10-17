# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:

		static std::string const attacks[10];

	public:

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &src);
		FragTrap & operator=(FragTrap const &src);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		bool		vaulthunter_dot_exe(std::string const & target);
};

#endif