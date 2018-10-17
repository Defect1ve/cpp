#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string			_target;
public:
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();
	void			action() const;
};

#endif