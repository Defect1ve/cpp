# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45)
{ }

RobotomyRequestForm::~RobotomyRequestForm(void)
{ }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("Robotomy", 72, 45)
{
	*this = src;
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	this->_target = src._target;
	return (*this);
}

void					RobotomyRequestForm::action(void) const
{
	std::string str;

	if (rand() % 2)
	{
		str = "say \"" + _target + " has been robotomized successfully\"";
		system ("afplay 1.mp3");
	}
	else
		str = "say \"Failure\"";
	system(str.c_str());
}