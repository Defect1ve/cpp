#ifndef	ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
#include "Zombie.hpp"

class	ZombieHorde
{
	public:
	
		ZombieHorde(int n);
		~ZombieHorde();
		void	announce(void);
	
	private:

		int		array_size;
		Zombie	*_array;
};

#endif