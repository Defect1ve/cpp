#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP
# include "ISpaceMarine.hpp"
# include <iostream>

class	AssaultTerminator : public ISpaceMarine
{
	private:

	public:

		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const&src);
		virtual ~AssaultTerminator();
		AssaultTerminator & operator=(AssaultTerminator const &src);
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

};

#endif