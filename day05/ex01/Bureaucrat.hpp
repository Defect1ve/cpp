#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
	public:

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void);
			virtual ~GradeTooHighException() throw();
			GradeTooHighException(GradeTooHighException const &src);
			void operator=(GradeTooHighException const &src);
			virtual const char * what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void);
			virtual ~GradeTooLowException() throw();
			GradeTooLowException(GradeTooLowException const &src);
			void operator=(GradeTooLowException const &src);
			virtual const char * what() const throw();
	};

	const std::string	_name;
	int					_grade;
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(Bureaucrat const&src);
	~Bureaucrat();
	std::string const	getName() const;
	int					getGrade() const;
	void				increment();
	void				decrement();
	void				signForm(Form &form);
	Bureaucrat & operator=(Bureaucrat const &src);
};
	std::ostream &operator<<(std::ostream & o, Bureaucrat &src);

#endif