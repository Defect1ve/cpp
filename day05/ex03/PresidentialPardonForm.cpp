# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential", 25, 5)
{ }

PresidentialPardonForm::~PresidentialPardonForm(void)
{ }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("Presidential", 25, 5)
{
	*this = src;
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->_target = src._target;
	return (*this);
}

void					PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}