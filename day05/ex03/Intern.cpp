# include "Intern.hpp"

Intern::Intern()
{ }

Intern::~Intern()
{ }

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern & Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

Intern::WrongTypeException::WrongTypeException()
{ }

Intern::WrongTypeException::~WrongTypeException() throw()
{ }

Intern::WrongTypeException::WrongTypeException(WrongTypeException const &src)
{
	(void)src;
}

void Intern::WrongTypeException::operator=(WrongTypeException const &src)
{
	(void)src;
}

const char * Intern::WrongTypeException::what() const throw()
{
	return ("Invalid type of form");
}

AForm		*Intern::makeForm(std::string name, std::string target)
{
	try
	{
		if (name == "presidential pardon")
		{
			PresidentialPardonForm *ppf = new PresidentialPardonForm(target);
			return (ppf);
		}
		else if (name == "robotomy request")
		{
			RobotomyRequestForm *rrf = new RobotomyRequestForm(target);
			return (rrf);
		}
		else if (name == "shrubbery creation")
		{
			ShrubberyCreationForm *scf = new ShrubberyCreationForm(target);
			return (scf);
		}
		else
			throw WrongTypeException();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (NULL);
}