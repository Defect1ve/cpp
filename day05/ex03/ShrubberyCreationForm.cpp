# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("Shrubbery", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	this->_target = src._target;
	return (*this);
}

void					ShrubberyCreationForm::action(void) const
{
	std::ofstream ofs (_target + "_shrubbery", std::ofstream::out);
	ofs << "                                              .\n \
                                   .         ;\n \
      .              .              ;%     ;;\n \
        ,           ,                :;%  %;\n \
         :         ;                   :;%;'     .,\n \
,.        %;     %;            ;        %;'    ,;\n \
  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n \
   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n \
    ;%;      %;        ;%;        % ;%;  ,%;'\n \
     `%;.     ;%;     %;'         `;%%;.%;'\n \
      `:;%.    ;%%. %@;        %; ;@%;%'\n \
         `:%;.  :;bd%;          %;@%;'\n \
           `@%:.  :;%.         ;@@%;'\n \
             `@%.  `;@%.      ;@@%;\n \
               `@%%. `@%%    ;@@%;\n \
                 ;@%. :@%%  %@@%;\n \
                   %@bd%%%bd%%:;\n \
                     #@%%%%%:;;\n \
                     %@@%%%::;\n \
                     %@@@%(o);  . '\n \
                     %@@@o%;:(.,'\n \
                 `.. %@@@o%::;\n \
                    `)@@@o%::;\n \
                     %@@(o)::;\n \
                    .%@@@@%::;\n \
                    ;%@@@@%::;.\n \
                   ;%@@@@%%:;;;.\n \
               ...;%@@@@@%%:;;;;,..";
	ofs.close();
}