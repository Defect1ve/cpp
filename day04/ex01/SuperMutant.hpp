#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:

		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(SuperMutant const &src);
		SuperMutant & operator=(SuperMutant const &src);
		virtual void takeDamage(int damage);
};

#endif