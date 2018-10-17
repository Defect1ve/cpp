#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm scf("scf_target");
	RobotomyRequestForm rrf("rrf_target");
	PresidentialPardonForm ppf("ppf_target");
	Bureaucrat man("John", 1);

	srand(time(0));

	std::cout << man << std::endl;

	std::cout << scf << std::endl;
	man.executeForm(scf);
	man.signForm(scf);
	man.executeForm(scf);

	std::cout << rrf << std::endl;
	man.executeForm(rrf);
	man.signForm(rrf);
	man.executeForm(rrf);

	std::cout << ppf << std::endl;
	man.executeForm(ppf);
	man.signForm(ppf);
	man.executeForm(ppf);

	Bureaucrat man1("Kolyan", 140);
	ShrubberyCreationForm scf1("Ezhik");

	std::cout << man1 << std::endl;
	std::cout << scf1 << std::endl;

	man1.signForm(scf1);

	std::cout << scf1 << std::endl;
 
	man1.executeForm(scf1);

	return (0);
}
