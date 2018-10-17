#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm *scf;
	AForm *rrf;
	AForm *ppf;

	scf = intern.makeForm("shrubbery creation", "Sharik");
	rrf = intern.makeForm("robotomy request", "Sharik");
	ppf = intern.makeForm("presidential pardon", "Sharik");
	std::cout << *scf << std::endl << *rrf << std::endl << *ppf << std::endl;
	delete scf;
	delete rrf;
	delete ppf;
	return (0);
}
