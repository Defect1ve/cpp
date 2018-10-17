#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(0), _sign_grade(150), _execute_grade(150)
{ }

AForm::~AForm()
{ }

AForm::AForm(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(0), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	try
	{
		(sign_grade < 1) ? throw AForm::GradeTooLowException() : 0;
		(sign_grade > 150) ? throw AForm::GradeTooHighException() : 0;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm(AForm const&AForm) : _sign_grade(AForm.getSignGrade()), _execute_grade(getExecuteGrade())
{
	*this = AForm;
}

AForm &AForm::operator=(AForm const&AForm)
{
	this->_signed = AForm._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream & o, AForm &src)
{
	o << src.getName() << ", signed: " << src.getSigned() << " has signed grade: " << src.getSignGrade() << " and execute grade: " << src.getExecuteGrade();
	return o;
}

std::string const	AForm::getName() const
{
	return (this->_name);
}

bool				AForm::getSigned() const
{
	return (this->_signed);
}

int					AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int					AForm::getExecuteGrade() const
{
	return (this->_execute_grade);
}

bool				AForm::beSigned(Bureaucrat const &bur)
{
	try
	{
		if (bur.getGrade() >= getSignGrade())
			throw AForm::GradeTooLowException();
		_signed = 1;
		return (true);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (false);
}

AForm::GradeTooLowException::GradeTooLowException(void)
{ }

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{ }

AForm::GradeTooHighException::GradeTooHighException(void)
{ }

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{ }

AForm::NotSignedException::NotSignedException(void)
{ }

AForm::NotSignedException::~NotSignedException(void) throw()
{ }

AForm::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	(void)src;
}

void AForm::GradeTooHighException::operator=(GradeTooHighException const &src)
{
	(void)src;
}

AForm::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	(void)src;
}

void AForm::GradeTooLowException::operator=(GradeTooLowException const &src)
{
	(void)src;
}

AForm::NotSignedException::NotSignedException(NotSignedException const &src)
{
	(void)src;
}

void AForm::NotSignedException::operator=(NotSignedException const &src)
{
	(void)src;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Too low value of grade");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Too high value of grade");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("This form is not signed");
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (_signed && executor.getGrade() <= getExecuteGrade())
		action();
}