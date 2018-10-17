#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	class NotSignedException : public std::exception
	{
		public:
			NotSignedException(void);
			virtual ~NotSignedException() throw();
			NotSignedException(NotSignedException const &src);
			void operator=(NotSignedException const &src);
			virtual const char * what() const throw();
	};

	AForm();
	AForm(AForm const&src);
	AForm(std::string, int, int);
	AForm &operator=(AForm const&src);
	virtual ~AForm();
	std::string	const	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	bool				beSigned(Bureaucrat const &b);
	void				execute(Bureaucrat const & executor) const;
	virtual	void		action()const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		int	const			_sign_grade;
		int const			_execute_grade;
};
	std::ostream &operator<<(std::ostream & o, AForm &src);

#endif