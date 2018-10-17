#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat man("Taras", 100);
	Form form("Form 42", 90, 1);

	std::cout << man << std::endl;

	std::cout << form << std::endl;

	man.signForm(form);

	for (int i = 0; i < 10; i++)
	man.increment();

	std::cout << man << std::endl;

	man.signForm(form);

	std::cout << form << std::endl;

	std::cout << "-----" << std::endl;

	try {
	Form form2("Another Form", 0, 1);
	}catch(std::exception & e) {
	std::cout << e.what() << std::endl;
	}

	try {
	Form form2("Another Form", 151, 1);
	} catch(std::exception & e) {
	std::cout << e.what() << std::endl;
	}

	try {
	Form form2("Another Form", 150, 1);
	Bureaucrat man2("Kolya", 150);

	man2.signForm(form2);
	} catch(std::exception & e) {
	std::cout << e.what() << std::endl;
	}

	return (0);
}