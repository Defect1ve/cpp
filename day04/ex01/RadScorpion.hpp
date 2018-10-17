#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:

	RadScorpion();
	virtual ~RadScorpion();
	RadScorpion(RadScorpion const &src);
	RadScorpion & operator=(RadScorpion const &src);
};

#endif