#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (OfficeBlock::PointerException & e)
	{
		std::cout << "Error in OfficeBook has been" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Another exception occured" << std::endl;
	}
}
