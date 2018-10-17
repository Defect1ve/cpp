#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP
# include "ISpaceMarine.hpp"
# include <iostream>

class	TacticalMarine : public ISpaceMarine
{
	private:

	public:

		TacticalMarine();
		TacticalMarine(TacticalMarine const&src);
		virtual ~TacticalMarine();
		TacticalMarine & operator=(TacticalMarine const &src);
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

};

#endif