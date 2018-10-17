#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
	class WrongTypeException : public std::exception
	{
		public:
			WrongTypeException(void);
			virtual ~WrongTypeException() throw();
			WrongTypeException(WrongTypeException const &src);
			void operator=(WrongTypeException const &src);
			virtual const char * what() const throw();
	};
		Intern();
		Intern(Intern const & src);
		Intern & operator=(Intern const &src);
		~Intern();
		AForm *makeForm(std::string, std::string) const;
};

#endif