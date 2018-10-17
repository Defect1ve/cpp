#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string			_target;
public:
	RobotomyRequestForm(std::string);
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm const & operator=(RobotomyRequestForm const &src);
	~RobotomyRequestForm();
	void		action() const;
};

#endif