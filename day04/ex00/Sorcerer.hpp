#ifndef SERCERER_HPP
# define SERCERER_HPP
# include <iostream>
# include "Victim.hpp"

class	Sorcerer
{
	public:

	std::string	getName(void) const;
	std::string getTitle(void) const;
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(Sorcerer const &src);
	Sorcerer & operator=(Sorcerer const &src);
	void polymorph(Victim const &src) const;

	private:

	Sorcerer();
	std::string 	_NAME;
	std::string 	_TITLE;
};

std::ostream &operator<<(std::ostream & o, Sorcerer const &src);

#endif