#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP
#include "Intern.hpp"

class OfficeBlock
{
private:

	Intern		const 	*_intern;
	Bureaucrat	const	*_signer;
	Bureaucrat	const	*_executor;
	OfficeBlock(OfficeBlock const & src);
	void operator=(OfficeBlock const &src);
public:
	class PointerException : public std::exception
	{
		public:
			PointerException(void);
			virtual ~PointerException() throw();
			PointerException(PointerException const &src);
			void operator=(PointerException const &src);
			virtual const char * what() const throw();
	};
	OfficeBlock();
	OfficeBlock(Intern *, Bureaucrat *, Bureaucrat*);
	~OfficeBlock();
	void	setIntern(Intern const &);
	void	setSigner(Bureaucrat const &);
	void	setExecutor(Bureaucrat const &);
	void	doBureaucracy(std::string, std::string);
};

#endif