#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void);
			virtual ~GradeTooLowException() throw();
			GradeTooLowException(GradeTooLowException const &src);
			void operator=(GradeTooLowException const &src);
			virtual const char * what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void);
			virtual ~GradeTooHighException() throw();
			GradeTooHighException(GradeTooHighException const &src);
			void operator=(GradeTooHighException const &src);
			virtual const char * what() const throw();
	};

	Form();
	Form(Form const&src);
	Form(std::string, int, int);
	Form &operator=(Form const&src);
	~Form();
	std::string	const	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	bool				beSigned(Bureaucrat const &b);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
};
std::ostream &operator<<(std::ostream & o, Form &src);
#endif