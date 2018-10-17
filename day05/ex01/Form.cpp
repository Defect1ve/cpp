#include "Form.hpp"

Form::Form() : _name("Form"), _signed(0), _sign_grade(150), _execute_grade(150)
{}

Form::~Form()
{ }

Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(0), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	try
	{
		(sign_grade < 1 || execute_grade < 1) ? throw Form::GradeTooLowException() : 0;
		(sign_grade > 150 || execute_grade > 150) ? throw Form::GradeTooHighException() : 0;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form(Form const&form) : _sign_grade(form.getSignGrade()), _execute_grade(form.getExecuteGrade())
{
	*this = form;
}

Form &Form::operator=(Form const&form)
{
	this->_signed = form._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream & o, Form &src)
{
	o << src.getName() << ", signed: " << src.getSigned() << " has signed grade: " << src.getSignGrade() << " and execute grade: " << src.getExecuteGrade();
	return o;
}

std::string const	Form::getName() const
{
	return (this->_name);
}

bool				Form::getSigned() const
{
	return (this->_signed);
}

int					Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int					Form::getExecuteGrade() const
{
	return (this->_execute_grade);
}

bool				Form::beSigned(Bureaucrat const &bur)
{
	try
	{
		if (bur.getGrade() < getSignGrade())
			throw Form::GradeTooLowException();
		_signed = 1;
		return (true);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (false);
}

Form::GradeTooLowException::GradeTooLowException(void)
{ }

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{ }

Form::GradeTooHighException::GradeTooHighException(void)
{ }

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{ }

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	(void)src;
}

void Form::GradeTooHighException::operator=(GradeTooHighException const &src)
{
	(void)src;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	(void)src;
}

void Form::GradeTooLowException::operator=(GradeTooLowException const &src)
{
	(void)src;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too low value of grade");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too high value of grade");
}
