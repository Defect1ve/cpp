#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class	Human
{
	public:
		Human(void);
		std::string identify(void);
		const Brain &getBrain(void);

	private:
		const Brain brain;
		std::string	name;
		int			age;
};

#endif