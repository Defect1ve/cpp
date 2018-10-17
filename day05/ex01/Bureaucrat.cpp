# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{ }

Bureaucrat::~Bureaucrat(void)
{ }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		(grade < 1) ? throw Bureaucrat::GradeTooLowException() : 0;
		(grade > 150) ? throw Bureaucrat::GradeTooHighException() : 0;
		this->_grade = grade;
	}
	catch(std::exception &e)
	{
		_grade = 150;
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{ }

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{ }

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{ }

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{ }

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	(void)src;
}

void Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &src)
{
	(void)src;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	(void)src;
}

void Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &src)
{
	(void)src;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low value of grade");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high value of grade");
}

Bureaucrat::Bureaucrat(Bureaucrat const&src)
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_grade = src._grade;
	return (*this);
}

std::string const Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::increment(void)
{
	try
	{
		if (this->_grade < 2)
			throw Bureaucrat::GradeTooLowException();
		this->_grade--;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void		Bureaucrat::decrement(void)
{
	try
	{
		if (this->_grade > 149)
			throw Bureaucrat::GradeTooHighException();
		this->_grade++;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream & o, Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}

void		Bureaucrat::signForm(Form &form)
{
	try
	{
		if (!form.beSigned(*this))
			throw Bureaucrat::GradeTooLowException();
		std::cout << getName() << " signs " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " becouse " << e.what();
	}
}